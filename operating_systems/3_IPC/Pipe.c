/* Pipes are uni-directional message boxes
   used to exchange messages between 2 related
   processes, i.e., parent-child, siblings of
   a parent process etc.
 */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int filedes[2];
	int ch;
	char *str1 = "This will go to stdout -- to screen\n";
	char *str2 = "This will go to stderr -- to screen\n";

	/* Every process has 3 descriptors when created */
	/* 0: stdin  -- by default the keyboard
	   1: stdout -- by default the screen
       2: stderr -- by default the screen
	*/

	write(1, str1, strlen(str1));
	write(2, str2, strlen(str2));

	printf("Press ENTER to continue\n");
	read(0, &ch, 1);

	/* Let's create a pipe */
	//pipe()  creates  a  pipe,  a unidirectional data channel that can
	//be used for interprocess communication.  The array pipefd is used to
    //return two file descriptors referring to the ends of the pipe.
	//pipefd[0] refers to the read end of the pipe.  pipefd[1] refers to the
    //write  end of the pipe.  Data written to the write end of the pipe is
	//buffered by the kernel until it is read from the read end of the pipe.
	pipe(filedes);

	printf("\nPipe descriptors: [0]: %d, [1]: %d\n", filedes[0], filedes[1]);


	if (fork() == 0){
		// Child.
		char buffer[100];

		//close read end of the pipe
		close(filedes[0]);

		while (1){
			memset(buffer, 0, 100);
			printf("Enter a message: ");
			gets(buffer);

			write(filedes[1], buffer, strlen(buffer));
			if (strcmp(buffer, "quit") == 0) break;
				memset(buffer, 0, 100);

		} /* end-while */

		printf("Child process terminates\n");

	}
	else {
		/* Parent. Echo server */
		char buffer[100];
		int msgNo = 1;
		int len;

		//close write end of the pipe
		close(filedes[1]);

		while (1){
			memset(buffer, 0, 100);
			sprintf(buffer, "PARENT PROCESS: <Msg No: %2d>", msgNo++);
			len = strlen(buffer);
			read(filedes[0], &buffer[len], 100);

			if (strcmp(&buffer[len], "quit") == 0) break;
				printf("[%s]\n", buffer);
		} /* end-while */

		printf("Parent process terminating\n");
	} /* end-else */

	return 0;
} /* end-main */
