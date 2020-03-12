//ThreadCreation.c
//Simple thread creation, termination example
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int test=0;
//---------------------------------------------------------
// some threads will executes the codes in this function
void *Thread1Proc(void *parameter){

	int *p = (int *)parameter;
	int i = 0;

	printf("Proc 1 | Start ! : %d\n", *p);

	while (i < 1000000000){
		if (i % 100000000 == 0)
			printf("Proc 1 | Argument: %d. i: %d\n", *p, i);
		i++;
	} /* end-while */

	return 0;    // Exit

}//end-Thread1Proc


//---------------------------------------------------------
// some threads will executes the codes in this function
void *Thread2Proc(void *parameter){

	double *p = (double *)parameter;
	int ch;

	printf("Proc 2 | Start ! : %5.2lf\n", *p);

	test=2;

	ch = getchar();
	printf("Proc 2 | CH: %d\n", ch);

	return 0;    // Exit

} //end-Thread1Proc

//---------------------------------------------------------
int main(int argc, char* argv[]){

	//thread pointers
	pthread_t threadId1, threadId2, threadId3;
	int arg1 = 66;
	double arg2 = 88.8;
	int arg3 = 77;


	// Create a thread executing Thread1Proc
	pthread_create(&threadId1, NULL, Thread1Proc, (void *)&arg1);


	// Create a third thread executing Thread2Proc
	pthread_create(&threadId2, NULL, Thread2Proc, (void *)&arg2);


	// Create a second thread executing Thread1Proc
	pthread_create(&threadId3, NULL, Thread1Proc, (void *)&arg3);


	// Have main thread wait for all threads to finish
	pthread_join(threadId1, NULL);
	printf("Thread1 terminated\n");

	pthread_join(threadId2, NULL);
	printf("Thread2 terminated\n");

	pthread_join(threadId3, NULL);
	printf("-->All threads have terminated. Main thread is now exiting...gv: %d\n", test);

	return 0;
} //end-main
