/* A message queue is a queue onto which messages can be placed.
   A message is composed of a message type (which is a number),
   and message data. A message queue can be either private, or public.
   If it is private, it can be accessed only by its creating
   process or child processes of that creator. If it's public,
   it can be accessed by any process that knows the queue's key.
   Several processes may write messages onto a message queue,
   or read messages from the queue. Messages may be read by type,
   and thus not have to be read in a FIFO order as is the case with pipes.
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <malloc.h>

#define MSG_QUEUE_ID  140
#define BUFFER_SIZE   100

typedef struct mymsg {
  long  mtype;     /* message type */
  char  mtext[1];  /* message text */
} mymsg;


#define SENDER     0
#define RECEIVER   1

int main(int argc, char *argv[]){

	int mqId;
	int type;
	int ret;


	if (argc < 2){
		printf("Usage: msgQueue -s|-r\n"); return 0;
	} /* end-if */

	if (strcmp(argv[1], "-s") == 0)
		type = SENDER;
	else
		type = RECEIVER;


	if (type == SENDER){
    // Sender code below

		/* create a public message queue, with access only to the owning user. */
		mqId = msgget(MSG_QUEUE_ID, IPC_CREAT | IPC_EXCL | 0600);
		if (mqId < 0){
			// Message box already exits. Try opening it.
			mqId = msgget(MSG_QUEUE_ID, 0);
			if (mqId < 0){
				printf("Can't create and open the message box\n");
				return 0;
			} /* end-if */
		} /* end-if */

		mymsg *pMsg = (mymsg *)malloc(sizeof(mymsg) + BUFFER_SIZE);

		while (1){
			pMsg->mtype = 1;               // Must be > 0
			printf("Msg to send > ");
			gets(pMsg->mtext);
			if (strlen(pMsg->mtext) == 0)
				continue;

			// Send the message to the message queue
			ret = msgsnd(mqId, pMsg, strlen(pMsg->mtext), 0);
			if (ret < 0){
				printf("msgsnd failed.\n"); return 0;
			} //end-if

			if (strcmp(pMsg->mtext, "quit") == 0)
				break;
		} //end-while

	}
	else {
		// Receiver code below
		mqId = msgget(MSG_QUEUE_ID, 0);
		if (mqId < 0){
			printf("Can not open the message box\n");
			return 0;
		} // end-if

		mymsg *pMsg = (mymsg *)malloc(sizeof(mymsg) + BUFFER_SIZE);
		printf("Ready to receive messages...\n");

		while (1){
			// Clean up the buffer
			memset(pMsg->mtext, 0, BUFFER_SIZE);

			// Send the message to the message queue
			ret = msgrcv(mqId,
						pMsg,
						BUFFER_SIZE,
						0,                   // Msgtype: 0 means the first message on the front of the queue
						MSG_NOERROR);        // Truncate message if it does not fit on the buffer
			if (ret < 0){
				printf("msgrcv failed.\n");

				if (errno == EACCES) printf("errno: EACCESS\n");
				else if (errno == EIDRM) printf("errno: EIDRM\n");
				else if (errno == EINTR) printf("errno: EINTR\n");
				else if (errno == E2BIG) printf("errno: E2BIG\n");
				else if (errno == EINVAL) printf("errno: EINVAL\n");
				else if (errno == ENOMSG) printf("errno: ENOMSG\n");

				return 0;
			} //end-if

			printf("Receiver rcvd: <%s>\n", pMsg->mtext);
			if (strcmp(pMsg->mtext, "quit") == 0)
				break;
		} //end-while
	} //end-else

	return 0;
} /* end-main */
