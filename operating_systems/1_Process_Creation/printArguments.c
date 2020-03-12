// PrintArguments.c
// Simply prints the arguments.

#include <stdio.h>

int main(int argc, char* argv[]){

	int i;

	for (i=0; i < argc; i++)
		printf("PrintArguments. Argument[%d]: <%s>\n", i, argv[i]);

	return 0;
}
