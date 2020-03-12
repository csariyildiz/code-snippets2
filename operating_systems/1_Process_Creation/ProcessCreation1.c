//ProcessCreation1.c
// Simple example to show how fork works
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int test = 2;
int main(int argc, char* argv[]){

	int childPid;
	char ch;

	//Create a new process
	childPid = fork();
	//At this line,
	//1. there are two processes and each process has its own resources.
	//2. But, both processes have the the same program codes.
	//3. The value of the variable childPid is 0(zero) for the child process
	//4. The value of the variable childPid is pid of the child process for the parent process
	if (childPid == 0){
		//Child process has been here.
		//Parent process has never been here.
		printf("This is the child. test: %d\n", test);
		test= 4;
		printf("This is the child. test: %d\n", test);
		printf("This is the child. childPid: %d\n", childPid);
	} else {
		//Child process has never been here.
		//Parent process has been here.
		test = 8;
		printf("This is the parent. childPid: %4d. test: %d\n", childPid, test);
	} /* end-else */

	scanf("%c",&ch);

	printf("Char is: %c. ChildPid: %d \n", ch, childPid);

	/* Common code that both the child and the parent execute */
	test = 9;
	printf("Both execute this code. childPid: %d, test: %d\n", childPid, test);

	return 0;
} // end-main
