/*
Требуется написать программу, которая запрашивает у пользователя строку 
и разбивает оную на слова. В результате разбора строки должен быть сформирован 
массив слов. Из слов, отличных от последнего, составляется новая строка. 
Слова в результирующую строку помещаются в обратном порядке с одним пробелом 
в качестве разделителя. После последнего слова пробел не добавляется.

Прежде, чем очередное слово помещается в результирующую строку, 
оно подвергается преобразованию в соответствии с вариантом.
Если результирующая строка не пустая, она выводится на экран следующим образом
printf("Result:␣%s\n", new_str);

Удалить из слова все последующие вхождения первой буквы.
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

#define ERR_ONE_WORD 6
#define ERR_ONLY_SAME_WORDS 7

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
    {
        check_str[len_check_str - 1] = '\0';
        *len_str = len_check_str - 1;
    }
    else
    {
        *len_str = len_check_str;
    }

    strcpy(str, check_str);
    

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

void del_repeat_first_char(char *word)
{
    size_t len_word = strlen(word);
    char first_char = word[0];

    char new_word[MAX_WORD_SIZE] = { ' ', first_char, '\0' };
    size_t len_new_word = 2;
    
    for (size_t i = 1; i < len_word; i++)
    {
        if (word[i] != first_char)
        {
            new_word[len_new_word++] = word[i];
        }
    }

    strcpy(word, new_word);
}

int fill_new_str_by_reversed_array(char arr_words[][MAX_WORD_SIZE], size_t count_words, char *new_str)
{
    if (count_words == 1)
        return ERR_ONE_WORD;

    int is_all_words_same = TRUE;

    char last_word[MAX_WORD_SIZE];

    strcpy(last_word, arr_words[count_words - 1]);

    for (int i = count_words - 2; i >= 0; i--)
    {
        if (strcmp(arr_words[i], last_word) != 0)
        {
            is_all_words_same = FALSE;
            del_repeat_first_char(arr_words[i]);
            strcat(new_str, arr_words[i]);
        }
    }

    if (is_all_words_same == TRUE)
        return ERR_ONLY_SAME_WORDS;

    return EXIT_SUCCESS;
}

int main(void)
{
    char str[MAX_STR_SIZE];
    size_t len_str = 0;
    
    char arr_words[MAX_STR_SIZE / 2][MAX_WORD_SIZE];
    size_t count_words = 0;

    char new_str[MAX_STR_SIZE] = "";
    
    int error;

    error = read_str(str, &len_str);
    if (error != EXIT_SUCCESS)
        return error;

    error = split_str(str, len_str, arr_words, &count_words);
    if (error != EXIT_SUCCESS)
        return error;

    error = fill_new_str_by_reversed_array(arr_words, count_words, new_str);
    if (error != EXIT_SUCCESS)
        return error;
    
    printf("Result:%s\n", new_str);

    return EXIT_SUCCESS;
}
