//ProcessCreation2.c
// Simple example to show how fork and exec works
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>



int main(int argc, char* argv[]){

	//Keeps arguments of a program
	char *args[10];
	int childPid;

/*
	//Set up parameters to be sent:
	args[0] = "printArguments";
	args[1] = "arg1";
	args[2] = "arg2";
	args[3] = "3";
	args[4] = "four";
	args[5] = NULL;
*/

  args[0] = "/bin/ls";
  args[1] = "-a";
  args[2] = "-l";
  args[3] = NULL;


	//Create a child process
	childPid = fork();
	if (childPid == 0){//Child Process

		// Execv example
		printf("-->Child process doing execv on PrintArguments\n");
		printf("-->Notice that execv will overlay the new process on top of the child process\n\n");
		execv("/bin/ls", args);
//		execv("./printArguments", args);
		//At this line, the child process has the codes of the program "printArguments"
		//the codes beyond this line will never execute.
		printf("-->This string will never execute!\n");

	}
	else{//Parent Process

		printf("...Parent is about wait for the child to terminate\n");
		/* This is the parent */
		waitpid(childPid, NULL, 0);
		printf("\n-->Parent resumes execution after the child is done\n\n");
	} /* end-else */

	return 0;
} // end-main
