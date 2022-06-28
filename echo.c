#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc == 1)
		return EXIT_FAILURE;

	write(1, argv[1], strlen(argv[1]));
	return EXIT_SUCCESS;
}
