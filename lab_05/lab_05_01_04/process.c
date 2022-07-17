#include "process.h"

int process(FILE *f, int *count)
{
	int left, middle, right;

	if (fscanf(f, "%d%d%d", &left, &middle, &right) == COUNT_READ_FIRST)
	{
		do 
		{
			if ((middle > left) && (middle > right))
				(*count)++;
			left = middle;
			middle = right;
		}
		while (fscanf(f, "%d", &right) == COUNT_READ);
	}
	else
	{
		return ERR_INPUT;
	}

	return EXIT_SUCCESS;
}
