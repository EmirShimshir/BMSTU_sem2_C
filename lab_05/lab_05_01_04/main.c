#include <stdio.h>

#include "process.h"
#include "consts.h"

int main(void)
{
	FILE *f = stdin;
	int count = 0;

	int error = process(f, &count);
	if (error != EXIT_SUCCESS)
		return error;

	fprintf(stdout, "%d", count);

	return EXIT_SUCCESS;
}
