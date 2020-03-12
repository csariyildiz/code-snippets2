// ProcessCreation3.c
// Simple example to show how fork and getpid works

#include <stdio.h>

int test = 2;

int main(int argc, char* argv[]){ //Parent Process

	int		childPid;
	char 	ch;

	childPid = fork();
	if (childPid == 0){//Child Process

		childPid = fork();//Create grandchild of parent process
		printf("This is the child/grandchild. test: %d pid: %d\n\n", test, getpid());

	}
	else {//Parent Process

		test= 8;
		fork();
		printf("This is the parent/child. childPid: %4d. test: %d\n\n", getpid(), test);

	} /* end-else */

	scanf("%c",&ch);
	printf("Char is: %c. Pid: %d\n", ch, getpid());

	/* Common code that the parent, childs and grandchild execute */
	test = 9;
	printf("All execute this code. pid: %d, test: %d\n\n", getpid(), test);

	return 0;
} // end-main
