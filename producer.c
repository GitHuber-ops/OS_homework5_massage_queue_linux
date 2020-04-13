#include "common.h"
#include "stdlib.h"

void *producer(void *args)
{
    int msg_que_id = get_msg_queue();
    while(1)
    {
        int sleep_time = rand() % 5;
        send_msg(msg_que_id, SERVER_TYPE, PRODUCER_MEG);
        printf(PRODUCER_MEG);
        sleep(sleep_time);
    }
}

// int main(){
//     printf("test point10\n");
//     producer();
//     return 0;
// }
