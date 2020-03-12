/* Implements basic synchronization (critical section) by locks */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//#include <semaphore.h>


// Shared global variable
int g = 0;

#define TIMES 10000000

/* Lock to gain mutual exclusive access to global variable "g" */
pthread_mutex_t mutex;


/*----------------------------------------------------
 * A sample thread
 */
void *ThreadProc(void *arg){
  int i;
  int l;

  printf("Thread %d starting to execute\n", *((int *)arg));
  /* Increment g TIMES many times */
  for (i=0; i < TIMES; i++){

    pthread_mutex_lock(&mutex);  		// Try to enter critical section
    l = g;
    l = l + 1;
    g = l;                                 // Critical section

    pthread_mutex_unlock(&mutex);      // Exit critical section

  } /* end-for */

  printf("Thread %d done\n", *((int *)arg));
} /* end-ThreadProc */




/*-------------------------------------------
 * Main
 */
int main(int argc,char *argv[]){
#define NO_OF_THREADS   5
  pthread_t threadIds[NO_OF_THREADS];
  int id[NO_OF_THREADS];
  int i;

  /* Initialize lock before use */
  pthread_mutex_init(&mutex,NULL);

  printf("Creating %d concurrent threads all changing global variable g...\n", NO_OF_THREADS);
  /* Create NO_OF_THREADS concurrent threads */
  for(i=0; i < NO_OF_THREADS; i++){
    id[i] = i+1;
    pthread_create(&threadIds[i], NULL, ThreadProc, &id[i]);
  } //end-for

  /* Wait until the threads are done. */
  for(i=0; i < NO_OF_THREADS; i++) pthread_join(threadIds[i], NULL);

  /* Done with the lock. Destroy the lock */
  pthread_mutex_destroy(&mutex);

  printf("Final value of g: %d.. should be: %d\n", g, TIMES*NO_OF_THREADS);

  return 0;
} /* end-main */
