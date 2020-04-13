#include "common.h"

void *consumer(void *arg)
{
    // printf("test point1\n");    //checked
    int msg_que_id = get_msg_queue();
    char buf[MSGSIZE];
    // printf("test point2\n");    //checked
    while(1){
	    // printf("test point3\n");    //checked
        int _rcv = recv_msg(msg_que_id, SERVER_TYPE, buf);
        if(_rcv == -1){
            printf("\t\t\t\t暂时没有商品\n");
        }else{
            printf(CONSUMER_MSG);    //bad
        }
        sleep(1);
    }
}

// int main(){
//     printf("test point0\n");
//     producer();
//     consumer();
// 	   return 0;    //checked
// }
