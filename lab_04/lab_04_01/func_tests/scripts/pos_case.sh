#!/bin/bash

# проверка количества аргументов
if [ $# -lt 2 ]; then
	exit 1
fi

in_test=$1
out_test=$2
out_prog="out_prog.txt"
valgrind="valgrind.txt"
command="../../app.exe"

# Коды ошибок

# Без Valgrind
test_p="0"
test_f="1"

# C Valgrind
test_p_val_p="2"
test_p_val_f="3"
test_f_val_p="4"
test_f_val_f="5"

# Если дан файл с аргументами, то передаём их исполняемому файлу app.exe
if [ $# -eq 3 ]; then
	command="$command $(cat "$3")"
fi

# Проверяем наличие флага для Valgrind
if [ -z "$USE_VALGRIND" ]; then
	$command < "$in_test" > "$out_prog"
	error="$?"
else
	valgrind -q --leak-check=full "$command" < "$in_test" > "$out_prog" 2> "$valgrind"
	error="$?"
fi

# проверка завершения программы
if ! [ "$error" -eq 0 ]; then # не нулевой код ошибки
	if [ -z "$USE_VALGRIND" ]; then	# нет флага Valgrind
		exit "$test_f"
	else # есть флаг
		if [ -s "$valgrind" ]; then	# есть ошибки в Valgrind
			exit "$test_f_val_f"
		else # нет ошибки в Valgrind
			exit "$test_f_val_p"
		fi	
	fi
fi

# сравниваем выходные данные программы и данные в тесте
if ! ./comparator.sh "$out_prog" "$out_test"; then # неверный тест
	if [ -z "$USE_VALGRIND" ]; then	# нет флага Valgrind
		exit "$test_f"
	else # есть флаг
		if [ -s "$valgrind" ]; then	# есть ошибки в Valgrind
			exit "$test_f_val_f"
		else # нет ошибки в Valgrind
			exit "$test_f_val_p"
		fi	
	fi
else # верный тест
	if [ -z "$USE_VALGRIND" ]; then	# нет флага Valgrind
		exit "$test_p"
	else # есть флаг
		if [ -s "$valgrind" ]; then	# есть ошибки в Valgrind
			exit "$test_p_val_f"
		else # нет ошибки в Valgrind
			exit "$test_p_val_p"
		fi
	fi
fi
