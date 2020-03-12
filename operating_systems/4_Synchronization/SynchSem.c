/* Implements basic synchronization (critical section) by locks */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>


// Shared global variable
int g = 0;

#define TIMES 10000000

/* Binary semaphore to gain mutual exclusive access to global variable "g" */
sem_t mutex;


/*----------------------------------------------------
 * A sample thread
 */
void *ThreadProc(void *arg){
  int i;
  int l;

  printf("Thread %d starting to execute\n", *((int *)arg));
  /* Increment g TIMES many times */
  for (i=0; i < TIMES; i++){

    sem_wait(&mutex);  		// Try to enter critical section
    l = g;
    l = l + 1;
    g = l;                                 // Critical section

    sem_post(&mutex);      // Exit critical section

  } /* end-for */

  printf("Thread %d done\n", *((int *)arg));
} /* end-ThreadProc */




/*-------------------------------------------
 * Main
 */
int main(int argc,char *argv[]){
#define NO_OF_THREADS   2
  pthread_t threadIds[NO_OF_THREADS];
  int id[NO_OF_THREADS];
  int i;

  /* Initialize lock before use */
  sem_init(&mutex, 0, 1);

  printf("Creating %d concurrent threads all changing global variable g...\n", NO_OF_THREADS);
  /* Create NO_OF_THREADS concurrent threads */
  for(i=0; i < NO_OF_THREADS; i++){
    id[i] = i+1;
    pthread_create(&threadIds[i], NULL, ThreadProc, &id[i]);
  } //end-for

  /* Wait until the threads are done. */
  for(i=0; i < NO_OF_THREADS; i++) pthread_join(threadIds[i], NULL);

  /* Done with the lock. Destroy the lock */
  sem_destroy(&mutex);

  printf("Final value of g: %d.. should be: %d\n", g, TIMES*NO_OF_THREADS);

  return 0;
} /* end-main */
