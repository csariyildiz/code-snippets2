/* Implements the bounded buffer problem
   There are 4 producers, 1 consumer.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>


#define NO_OF_SLOTS       8
int     Q[NO_OF_SLOTS];
int     front = -1;           /* Front of the queue */
int     rear  = -1;           /* Rear of the queue */

pthread_mutex_t mutex;        /* Mutual exclusion semaphore to gain access to front and rear */
sem_t           full;         /* # of full slots. Initially 0 */
sem_t           empty;        /* # of empty slots. Initially NO_OF_SLOTS */


int    itemCounter = 0;       /* Id of the next item to be inserted to the Queue */


/*----------------------------------------------------
 * Producer thread
 */
void *Producer(void *arg){
	int pid;

	memcpy(&pid, arg, sizeof(int));
	printf("Producer <%d> started\n", pid);


	/* Insert items to queue until itemCounter is 100 */
	while (itemCounter < 100){
		//sem_wait(&empty);             /* Wait until an empty slot opens */

	//	pthread_mutex_lock(&mutex);   /* Get exclusive access to Queue */

		itemCounter++;                /* Next item to be inserted */
		rear = rear + 1;              /* Compute the slot where we will insert the next item */
       if (rear >= NO_OF_SLOTS)
			rear = 0;
       Q[rear] = itemCounter;

		printf("P<%d> inserted item <%4d> into the Q\n", pid, itemCounter);
      // pthread_mutex_unlock(&mutex);  /* Done inserting item to the queue */

       //sem_post(&full);               /* Notify consumer: One more full slot in the Queue */
	} /* end-while */
} /* end-Producer */




/*----------------------------------------------------
 * Consumer thread
 */
void *Consumer(void *arg){
	int item = 0;

	printf("Consumer started\n");

	while (item < 100){
	//	sem_wait(&full);             /* Wait until a slot is full */

		//pthread_mutex_lock(&mutex);  /* Get exclusive access to Queue */

		front = front + 1;           /* Compute the slot where the next item resides */
       if (front >= NO_OF_SLOTS)
			front = 0;
       item = Q[front];

		printf("Removed  item <%4d> from the Q\n", item);
       //pthread_mutex_unlock(&mutex); /* Done removing item from the Q */

       //sem_post(&empty);             /* Notify producers: One more empty slot in the Queue */
	} /* end-while */
} /* end-Consumer */


/*-------------------------------------------
 * Main
 */
int main(int argc,char *argv[]){
	int i, j;
	pthread_t producerIds[4];
	pthread_t consumerId;
	int ids[4] = {1, 2, 3, 4};


	pthread_mutex_init(&mutex,NULL);
	sem_init(&full, 0, 0);             /* No slots are full at the beginning */
	sem_init(&empty, 0, NO_OF_SLOTS);  /* All slots are empty at the beginning */

	/* Create 1 consumer thread */
	pthread_create(&consumerId, NULL, Consumer, NULL);

	/* Create 4 producers */
	for(i=0;i<4;i++)
		pthread_create(&producerIds[i], NULL, Producer, &ids[i]);

	/* Wait until the threads are done. */
	pthread_join(consumerId, NULL);
	for(i=0;i<4;i++)pthread_join(producerIds[i], NULL);

	return 0;
} /* end-main */
