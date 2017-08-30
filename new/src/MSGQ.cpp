/**
 * \file   
 * \author Philipp Johannes 
 * \date   Juni 2017
 * \brief  Codefile für IPC
 */

#include "../inc/MSGQ.h"



void MSGQ::send_message(int qid, MSG_BUFFER *qbuf, long type, FRAME *data)
{
    struct msqid_ds myqueue_ds;

    msgctl(qid, IPC_STAT, &myqueue_ds);
    if(myqueue_ds.msg_qnum < MSG_QUEUE_SIZE)
    {
        qbuf->mtype = type;
        memcpy(&qbuf->data, data, sizeof(FRAME));

        if((msgsnd(qid, (MSG_BUFFER *)qbuf, sizeof(FRAME), IPC_NOWAIT)) ==-1)
        {
            printf("error Sending a message ...\n");
            perror("msgsnd");
        }
    }
}

uint8_t MSGQ::read_message(int qid, MSG_BUFFER *qbuf, long type)
{
    int res;
    struct msqid_ds myqueue_ds;

    qbuf->mtype = type;
    res = msgrcv(qid, (MSG_BUFFER *)qbuf, sizeof(FRAME), type, IPC_NOWAIT);
    if( res < 0 ) 
    {
        return 0;
    }
    else
    {
        printf("height actual data: %d\n", qbuf->data.control.fanLeft);
        return 1;
    }
}

void MSGQ::remove_queue(int qid)
{
    msgctl(qid, IPC_RMID, 0);
}

void MSGQ::change_queue_mode(int qid, char *mode)
{
    struct msqid_ds myqueue_ds;

    /* Get current info */
    msgctl(qid, IPC_STAT, &myqueue_ds);

    /* Convert and load the mode */
    sscanf(mode, "%ho", &myqueue_ds.msg_perm.mode);

    /* Update the mode */
    msgctl(qid, IPC_SET, &myqueue_ds);
}
void send_con_state(int qid)
{

}

void MSGQ::send_con_state(int qid, STATE_BUFFER *qbuf, long type, INTERNAL *data)
{
	struct msqid_ds myqueue_ds;

    msgctl(qid, IPC_STAT, &myqueue_ds);
    if(myqueue_ds.msg_qnum < MSG_QUEUE_SIZE)
    {
		qbuf->mtype = type;
		memcpy(&qbuf->data, data, sizeof(INTERNAL));

		if((msgsnd(qid, (STATE_BUFFER *)qbuf, sizeof(INTERNAL), IPC_NOWAIT)) ==-1)
		{
			printf("error Sending a message ...\n");
			perror("msgsnd");
		}
    }
}

uint8_t MSGQ::read_con_state(int qid, STATE_BUFFER *qbuf, long type)
{
	int res;
	struct msqid_ds myqueue_ds;

    qbuf->mtype = type;
    res = msgrcv(qid, (STATE_BUFFER *)qbuf, sizeof(INTERNAL), type, IPC_NOWAIT);
	if( res < 0 ) 
	{
		return 0;
    }
    else
    {
    	return 1;
    }
}



