#!/bin/bash

# количество ошибочных тестов
count_errors=0
pos=0
neg=0

# Коды ошибок

# Без Valgrind
test_p="0"
test_f="1"

# C Valgrind
test_p_val_p="2"
test_p_val_f="3"
test_f_val_p="4"
test_f_val_f="5"

# обработка позитивных тестов
files="../data/pos_??_in.txt"
for file_in in $files; do

	# находим номер теста
	number=$(echo "$file_in" | grep -o "[0-9]*")

	# проверка на наличие тестов
	if [ -z "$number" ]; then
		break
	fi

	pos=1

	# названия выходного тестового файла и файла с аргументами
	file_out="../data/pos_""$number""_out.txt"
	file_args="../data/pos_""$number""_args.txt"

	# если выходной файл существует, передаем входной и выходной файлы 
	# в pos_case.sh

	# если не существует, то считаем тест проваленным и переходим к
	# следующему тесту

	if [ -f "$file_out" ]; then
		command="./pos_case.sh ""$file_in ""$file_out"
	else
		echo "POS_""$number"": FAILED"
		count_errors=$((count_errors + 1))
		continue
	fi

	# если существует файл с аргументами, добавляем его в pos_case.sh
	if [ -f "$file_args" ]; then 
		command="$command ""$file_args"
	fi

	$command
	error="$?"

	# выводим результат в соответствии с кодом ошибки ./pos_case.sh
	if [ "$error" -eq "$test_p" ]; then
		echo "POS_""$number"": PASSED"
	fi
	if [ "$error" -eq "$test_f" ]; then
		echo "POS_""$number"": FAILED"
		count_errors=$((count_errors + 1))
	fi
	if [ "$error" -eq "$test_p_val_p" ]; then
		echo "POS_""$number"": PASSED. Memory: PASSED"
	fi
	if [ "$error" -eq "$test_p_val_f" ]; then
		echo "POS_""$number"": PASSED. Memory: FAILED"
	fi
	if [ "$error" -eq "$test_f_val_p" ]; then
		echo "POS_""$number"": FAILED. Memory: PASSED"
		count_errors=$((count_errors + 1))
	fi
	if [ "$error" -eq "$test_f_val_f" ]; then
		echo "POS_""$number"": FAILED. Memory: FAILED"
		count_errors=$((count_errors + 1))
	fi
done

# обработка негативных тестов 
files="../data/neg_??_in.txt"
for file_in in $files; do

	# находим номер теста
	number=$(echo "$file_in" | grep -o "[0-9]*")

	# проверка на наличие тестов
	if [ -z "$number" ]; then
		break
	fi

	neg=1

	# передаем входной тестовый файл в ./neg_case.sh
	command="./neg_case.sh ""$file_in"

	# название файла с аргументами
	file_args="../data/neg_""$number""_args.txt"

	# если существует файл с аргументами, добавляем его в ./neg_case.sh
	if [ -f "$file_args" ]; then 
		command="$command ""$file_args"
	fi

	
	$command
	error="$?"

	# выводим результат в соответствии с кодом ошибки ./neg_case.sh
	if [ "$error" -eq "$test_p" ]; then
		echo "NEG_""$number"": PASSED"
	fi
	if [ "$error" -eq "$test_f" ]; then
		echo "NEG_""$number"": FAILED"
		count_errors=$((count_errors + 1))
	fi
	if [ "$error" -eq "$test_p_val_p" ]; then
		echo "NEG_""$number"": PASSED. Memory: PASSED"
	fi
	if [ "$error" -eq "$test_p_val_f" ]; then
		echo "NEG_""$number"": PASSED. Memory: FAILED"
	fi
	if [ "$error" -eq "$test_f_val_p" ]; then
		echo "NEG_""$number"": FAILED. Memory: PASSED"
		count_errors=$((count_errors + 1))
	fi
	if [ "$error" -eq "$test_f_val_f" ]; then
		echo "NEG_""$number"": FAILED. Memory: FAILED"
		count_errors=$((count_errors + 1))
	fi
done

# вспомогательная информация

if [ "$count_errors" -eq 0 ]; then
	echo "All tests passed." 
else
	echo "Failed $count_errors tests." 
fi

if [ "$pos" -eq 0 ]; then
	echo "No positive tests." 
fi

if [ "$neg" -eq 0 ]; then 
	echo "No negative tests."
fi

exit "$count_errors"
