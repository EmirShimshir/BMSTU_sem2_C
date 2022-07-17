/*
Требуется написать программу, которая запрашивает у пользователя нужное по 
заданию количество строк, разбивает оные на слова и выполняет обработку слов. 
Разбиение строки на слова реализуется студентом самостоятельно — использовать 
для выделения слов библиотечные функции, например, scanf, sscanf или strtok, запрещено.

В результате разбора каждой строки должен быть сформирован массив слов, после чего 
выполняется обработка всех полученных массивов.

Результаты выводятся обязательно после фразы «Result:␣». Слова и числа 
разделяются одним пробелом.

В случае если решение задачи не может быть получено, на экран ничего не выводится, 
возвращается ненулевой код возврата.

Ввести две строки. 
Для каждого слова из первой строки (повторяющиеся в этой же строке слова не обрабатываются) определить, 
входит ли оно во вторую строку. Программа должна вывести пары «слово yes|no». 
Каждая пара выводится на отдельной строке. 
Слова выводятся в том порядке, в котором они встретились в первой строке.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define MAX_STR_SIZE 257
#define MAX_WORD_SIZE 17

#define ERR_EMPTY_STR 1
#define ERR_STR_LEN 2
#define ERR_INPUT 3

#define ERR_WORD_LEN 4
#define ERR_NO_WORDS 5

#define TRUE 1
#define FALSE 0

#define SEPARATORS " ,;:-.!?"

int read_str(char *str, size_t *len_str)
{
    char check_str[MAX_STR_SIZE + 1];

    char *p = fgets(check_str, MAX_STR_SIZE + 1, stdin);

    if (p == NULL)
        return ERR_INPUT; 

    if (check_str[0] == '\n')
        return ERR_EMPTY_STR;

    size_t len_check_str = strlen(check_str);
    
    if ((len_check_str == MAX_STR_SIZE) && (check_str[len_check_str - 1] != '\n'))
        return ERR_STR_LEN;

    if (check_str[len_check_str - 1] == '\n')
        check_str[len_check_str - 1] = '\0';

    strcpy(str, check_str);
    *len_str = len_check_str - 1;

    return EXIT_SUCCESS;
}

int split_str(char *str, size_t len_str, char arr_words[][MAX_WORD_SIZE], size_t *count_words)
{
    char word[MAX_WORD_SIZE];
    size_t len_word = 0;

    for (size_t i = 0; i <= len_str; i++)
    {
        if (strchr(SEPARATORS, str[i]))
        {
            if (len_word > 0)
            {
                word[len_word] = '\0';
                strcpy(arr_words[(*count_words)++], word);
                len_word = 0;
            }
        }
        else if (len_word < MAX_WORD_SIZE - 1)
            word[len_word++] = str[i];
        else
            return ERR_WORD_LEN;
    }

    if (*count_words == 0)
        return ERR_NO_WORDS;

    return EXIT_SUCCESS;
}

int is_repeat(char arr_words[][MAX_WORD_SIZE], size_t index)
{
    for (size_t i = 0; i < index; i++)
    {
        if (strcmp(arr_words[i], arr_words[index]) == 0)
        {   
            return i != index;
        }
    }

    return FALSE;
}

void print_occurrences(char arr_words1[][MAX_WORD_SIZE], size_t count_words1, char arr_words2[][MAX_WORD_SIZE], size_t count_words2)
{
    printf("Result: ");
    for (size_t i = 0; i < count_words1; i++)
    {
        if (is_repeat(arr_words1, i) == FALSE)
        {
            int is_occur = FALSE;
            for (size_t j = 0; j < count_words2; j++)
            {
                if (strcmp(arr_words1[i], arr_words2[j]) == 0)
                    is_occur = TRUE;
            }

            printf("%s %s\n", arr_words1[i], is_occur ? "yes" : "no");
        }
    }
} 

int main(void)
{
    char str1[MAX_STR_SIZE];
    char str2[MAX_STR_SIZE];

    size_t len_str1 = 0;
    size_t len_str2 = 0;

    char arr_words1[MAX_STR_SIZE / 2][MAX_WORD_SIZE];
    char arr_words2[MAX_STR_SIZE / 2][MAX_WORD_SIZE];

    size_t count_words1 = 0;
    size_t count_words2 = 0;

    int error;

    error = read_str(str1, &len_str1);
    if (error != EXIT_SUCCESS)
        return error;

    error = read_str(str2, &len_str2);
    if (error != EXIT_SUCCESS)
        return error;

    error = split_str(str1, len_str1, arr_words1, &count_words1);
    if (error != EXIT_SUCCESS)
        return error;

    error = split_str(str2, len_str2, arr_words2, &count_words2);
    if (error != EXIT_SUCCESS)
        return error;

    print_occurrences(arr_words1, count_words1, arr_words2, count_words2);

    return EXIT_SUCCESS;
}
