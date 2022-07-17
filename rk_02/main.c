#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define EXIT_SUCCESS 0
#define ERR_ARGS 1
#define ERR_COUNT_STR 2
#define ERR_EMPTY 3
#define ERR_LONG_STR 4
#define ERR_NO_PARS 5

#define M 100
#define N 6

typedef struct
{
	size_t count;
	char words[M][N + 1];
} struct_t;

typedef struct
{
	char word1[N + 1];
	char word2[N + 1];
} struct_pars_t;

int get_words(FILE *f, struct_t *words_struct)
{
	size_t n = 0;
	
	while ((fscanf(f, "%s", words_struct->words[n]) == 1) && (n <= M))
	{
		if (strlen(words_struct->words[n]) > N)
		{
			return ERR_COUNT_STR;
		}
		n++;
		
		
	}
	
	if (n == 0)
		return ERR_EMPTY;
		
	if (n == N)
			return ERR_LONG_STR;
			
	words_struct->count = n;
	
	return EXIT_SUCCESS;
}

void reverce_word(char *word)
{
	char temp_word[N + 1];
	
	for (int i = 0; i < N; i++)
	{
		temp_word[i] = word[N - 1 - i];
	}
	
	temp_word[N] = '\0';
	
	strcpy(word, temp_word);
}
		

int add_pars_to_arr(struct_pars_t *arr_pars, struct_t *words_struct, size_t *n)
{	
	for (size_t i = 0; i < words_struct->count; i++)
	{
		reverce_word(words_struct->words[i]);
		for (size_t j = 0; j < words_struct->count; j++)
		{
		
			if (strcmp(words_struct->words[i], words_struct->words[j]) == 0 && i != j)
			{
				reverce_word(words_struct->words[i]);
				strcpy(arr_pars[*n].word1, words_struct->words[i]);
				strcpy(arr_pars[*n].word2, words_struct->words[j]);
				
				(*n)++;
			}
		}
	}
	
	if (*n == 0)
		return ERR_NO_PARS;
		
	return EXIT_SUCCESS;
}

void write_pars(FILE *f, struct_pars_t *arr_pars, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		fprintf(f, "%s, %s\n", arr_pars[i].word1, arr_pars[i].word2);
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return ERR_ARGS;
		
	FILE *f = fopen(argv[1], "r");
	if (f == NULL)
		return ERR_ARGS;
		
	struct_t words_struct;
	
	int error = get_words(f, &words_struct);
	if (error != EXIT_SUCCESS)
	{
		fclose(f);
		return error;
	}	
	fclose(f);
		
	struct_pars_t arr_pars[M];
	size_t n = 0;
	
	add_pars_to_arr(arr_pars, &words_struct, &n);
	
	FILE *f_out = fopen(argv[2], "w");
	
	write_pars(f_out, arr_pars, n);
	
	fclose(f_out);
	
	return EXIT_SUCCESS;	
}
