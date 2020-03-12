/* On a Unix system, each process has its own virtual address space,
   and the system makes sure no process would access the memory area
   of another process. This means that if one process corrupts its memory's
   contents, this does not directly affect any other process in the system.

   With shared memory, we declare a given section in the memory as one that will
   be used simultaneously by several processes. This means that the data found in
   this memory section (or memory segment) will be seen by several processes. This
   also means that several processes might try to alter this memory area at the
   same time, and thus some method should be used to synchronize their access to
   this memory area (need for process synchronization ...).
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_ID   100

#define SENDER     0
#define RECEIVER   1

int main(int argc, char *argv[]){
	int shm_id;
	int mqId;
	int type;
	int ret;

	if (argc < 2){
		printf("Usage: SharedMem -s|-r\n");
		return 0;
	} /* end-if */

  	if (strcmp(argv[1], "-s") == 0)
		type = SENDER;
  	else
  		type = RECEIVER;

  	if (type == SENDER){
  		// Sender code below
  		/* these variables are used to specify where the page is attached. */
  		char* shm_addr;

  		/* allocate a shared memory segment with size of 2048 bytes */
  		/* accessible only to the current user. */
  		shm_id = shmget(SHM_ID, 2048, IPC_CREAT | 0600);
  		if (shm_id == -1) {
			perror("shmget: ");
			exit(1);
  		} //end-if

  		/* attach the given shared memory segment, at some free position */
  		/* that will be allocated by the system.                         */
  		shm_addr = shmat(shm_id, NULL, 0);
  		if (!shm_addr) { /* operation failed. */
  			perror("shmat: ");
  			exit(1);
		 } /* end-if */

  		// Set shared memory segment to all 0's
  		memset(shm_addr, 0, 2048);

  		while (1){
  			unsigned int *pSynch = (unsigned int *)shm_addr;
  			unsigned int *pMsgSize = (unsigned int *)(shm_addr + 4);
  			unsigned char *pMsg = (unsigned char *)(shm_addr + 8);

  			printf("Msg to send > ");
  			gets(pMsg);
  			if (strlen(pMsg) == 0)
  				continue;

  			*pSynch = 1;            // Notify the receiver that the message is ready to be read.

  			if (strcmp(pMsg, "quit") == 0)
  				break;
  			while (*pSynch == 1)
  				sleep(1);  // Wait until the receiver reads the message
  		} //end-while

  	}
  	else {
  		/* these variables are used to specify where the page is attached. */
  		char* shm_addr;

		// Receiver code below
		/* allocate a shared memory segment with size of 2048 bytes */
  		/* accessible only to the current user. */
  		shm_id = shmget(SHM_ID, 2048, IPC_CREAT | 0600);
  		if (shm_id == -1) {
  			perror("shmget: ");
  			exit(1);
  		} //end-if

  		/* attach the given shared memory segment, at some free position */
  		/* that will be allocated by the system.                         */
  		shm_addr = shmat(shm_id, NULL, 0);
  		if (!shm_addr) { /* operation failed. */
  			perror("shmat: ");
  			exit(1);
  		} /* end-if */

  		while (1){
  			unsigned int *pSynch = (unsigned int *)shm_addr;
  			unsigned int *pMsgSize = (unsigned int *)(shm_addr + 4);
  			unsigned char *pMsg = (unsigned char *)(shm_addr + 8);

  			// Wait until the sender copies a message to the shared memory
    	  while (*pSynch == 0)
    		  sleep(1);

    	  printf("Receiver rcvd: <%s>\n", pMsg);
    	  if (strcmp(pMsg, "quit") == 0)
    		  break;

    	  *pSynch = 0;   // Notify the sender that the message has been read.
  		} //end-while
  	} //end-else

  	return 0;
} /* end-main */
