#include"common.h"


int gen_msg_queue(int msgflag){
    // printf("test point4\n");    //checked
    // geneate a unique key to get a new queue.
    key_t _k = ftok(PATHNAME, PROJ_ID);

    int msg_que_id = msgget(_k, msgflag);
    // msgget will return -1 if fails, otherwise it will return the queue id.
    if(msg_que_id == -1){
        perror("msgget\n");
        return -1;
    }
    return msg_que_id;
}


int create_msg_queue(){
    // printf("test point5\n");
    // give new queue a right permission and generate a new queue.
    return gen_msg_queue(IPC_CREAT|IPC_EXCL|0666);
}

int destory_msg_queue(int msg_que_id){
    // printf("test point6\n");
    int _ret = msgctl(msg_que_id, IPC_RMID, 0);
    // msgctl returns -1 if something gone wrong...
    if(_ret == -1){
        perror("msgctl");
        return -1;
    }
    return 0;
   }

int get_msg_queue(){
    // printf("test point7\n");    //checked
    return gen_msg_queue(IPC_CREAT);
}

int send_msg(int msg_que_id, long type, const char *_send_info){
    // printf("test point8\n");
    struct msgbuf msg;
    msg.mtype = type;
    strcpy(msg.mtext, _send_info);

    // printf("second test1\n");
    int _snd = msgsnd(msg_que_id, &msg, sizeof(msg.mtext), 0);
    // printf("second test2\n");

    if( _snd < 0){
        perror("msgsnd");
        return -1;
    }
    return 0;
    }


int recv_msg(int msg_que_id, long type, char buf[]){
    // printf("test point9\n");    //checked
    struct msgbuf msg;
    int _rcv = msgrcv(msg_que_id, &msg, sizeof(msg.mtext), type, IPC_NOWAIT);
    // printf("%d", _rcv);
    // printf("second test0\n");
    strcpy(buf, msg.mtext);
    return _rcv;
}

