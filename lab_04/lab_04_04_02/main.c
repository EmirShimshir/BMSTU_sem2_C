/*
Для представления даты выбрано следующее представление: «[D]D␣month␣YYYY»
Месяц это одна из строк «january», «february», «march», «april», «may», «june», 
«july», «august», «september», «october», «FALSEvember», «december». 
Составные части даты могут разделяться произвольным количеством пробелов. 
Написание месяца не чувствительно к регистру символов.

На вход программе подаётся произвольная строка. 
Строка может начинаться и заканчиваться произвольным количеством пробельных символов. 
Программа должна вывести только сообщение «YES», если в строке содержится правильная дата 
в указанном формате, и только «NO» — в противном случае. Обратите внимание, 
что проверить нужно не только валидность написания даты, но и валидность самой даты 
(например, дата «40 april 2010» правильная по написанию, но не по значению). 
Не забудьте про правила для високосных годов.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_SIZE 257

#define ERR_EMPTY_STR 1
#define ERR_STR_LEN 2
#define ERR_INPUT 3

#define ERR 6

#define ERR_WORD_LEN 4
#define ERR_NO_WORDS 5

#define TRUE 1
#define FALSE 0

#define DIGITS "0123456789"

#define MONTH_COUNT 12
#define WORDS_COUNT 3

typedef struct date 
{
    char str_day[MAX_STR_SIZE];
    int int_day;            
    char str_month[MAX_STR_SIZE];            
    size_t index_month;           
    char str_year[MAX_STR_SIZE]; 
    int int_year;           
} date_t;

char months[MONTH_COUNT][MAX_STR_SIZE] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };

int days_in_months[MONTH_COUNT] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int read_str(char *str, size_t *len_str)
{
    char check_str[MAX_STR_SIZE + 1];

    char *p = fgets(check_str, MAX_STR_SIZE + 1, stdin);

    if (p == NULL)
        return ERR_EMPTY_STR;

    if (check_str[0] == '\n')
    {
        strcpy(str, check_str);
        *len_str = 1;
        return EXIT_SUCCESS;
    }

    size_t len_check_str = strlen(check_str);
    
    if ((len_check_str == MAX_STR_SIZE) && (check_str[len_check_str - 1] != '\n'))
        return ERR_STR_LEN;

    if (check_str[len_check_str - 1] == '\n')
        check_str[len_check_str - 1] = '\0';

    strcpy(str, check_str);
    *len_str = len_check_str - 1;

    return EXIT_SUCCESS;
}

int split_str(char *str, size_t len_str, char arr_words[][MAX_STR_SIZE], size_t *count_words)
{
    char word[MAX_STR_SIZE];
    size_t len_word = 0;

    for (size_t i = 0; i <= len_str; i++)
    {
        if (isspace(str[i]) || str[i] == '\0')
        {
            if (len_word > 0)
            {
                word[len_word] = '\0';
                strcpy(arr_words[(*count_words)++], word);

                len_word = 0;
            }
        }
        else if (len_word < MAX_STR_SIZE - 1)
            word[len_word++] = str[i];
        else
            return ERR_WORD_LEN;
    }

    if (*count_words != WORDS_COUNT)
        return ERR_NO_WORDS;

    return EXIT_SUCCESS;
}

int is_init_date(char *str, date_t *date)
{
    char arr_words[MAX_STR_SIZE / 2][MAX_STR_SIZE];
    size_t count_words = 0;

    size_t len_str = strlen(str);

    if (split_str(str, len_str, arr_words, &count_words))
        return FALSE;

    strcpy(date->str_day, arr_words[0]);
    strcpy(date->str_month, arr_words[1]);
    strcpy(date->str_year, arr_words[2]);

    return TRUE;
}

int is_correct_day(date_t *date)
{
    char *day = date->str_day;
    size_t len = strlen(day);

    for (size_t i = 0; i < len; i++)
    {
        if (!isdigit(day[i]))
            return FALSE;
    }

    int result = 0;
    for (size_t i = 0; i < len; i++)
    {
        result = 10 * result + (day[i] - '0');
    }

    date->int_day = result;

    return TRUE;
}

int is_correct_month(date_t *date)
{
    char month_lower[MAX_STR_SIZE];

    size_t len_str_month = strlen(date->str_month);

    for (size_t i = 0; i < len_str_month; i++)
        month_lower[i] = tolower(date->str_month[i]);

    month_lower[len_str_month] = '\0';

    for (size_t i = 0; i < MONTH_COUNT; i++)
    {
        if (!strcmp(month_lower, months[i]))
        {
            date->index_month = i;
            return TRUE;
        }
    }

    return FALSE;
}

int is_correct_year(date_t *date)
{
    char *year = date->str_year;
    size_t len = strlen(year);

    for (size_t i = 0; i < len; i++)
    {
        if (!isdigit(year[i]))
            return FALSE;
    }

    int result = 0;
    for (size_t i = 0; i < len; i++)
    {
        result = 10 * result + (year[i] - '0');
    }

    if (result == 0)
        return FALSE;

    date->int_year = result;

    return TRUE;
}

int is_correct_date(date_t *date)
{
    if (!is_correct_day(date))
        return FALSE;

    if (!is_correct_month(date))
        return FALSE;

    if (!is_correct_year(date))
        return FALSE;

    if ((date->int_year % 4 == 0 && date->int_year % 100 != 0) || (date->int_year % 400 == 0))
        days_in_months[1] = 29;

    if ((date->int_day > 0) && (date->int_day <= days_in_months[date->index_month]))
        return TRUE;

    return FALSE;
}

int main(void)
{
    char str[MAX_STR_SIZE];
    size_t len_str = 0;
    
    int error;

    error = read_str(str, &len_str);
    if (error != EXIT_SUCCESS)
        return error;

    date_t date;

    int answer;

    answer = is_init_date(str, &date);
    if (answer != TRUE)
    {
        printf("NO");
        return EXIT_SUCCESS;
    }

    answer = is_correct_date(&date);
    if (answer != TRUE)
    {
        printf("NO");
        return EXIT_SUCCESS;
    }

    printf("YES");
    
    return EXIT_SUCCESS;
}
