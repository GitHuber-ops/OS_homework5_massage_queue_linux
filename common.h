#ifndef _COMMON_H_
#define _COMMON_H_
#include <string.h>  // strcpy
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>  // read
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>

#define PATHNAME "./"
#define PROJ_ID  'a'
#define MSGSIZE 1024
#define CONSUMER_MSG "取走了一个商品\n"
#define PRODUCER_MEG "\t\t生产了一个商品\n"

#define SERVER_TYPE 1   // 服务端发送消息类型
#define CLIENT_TYPE 2   // 客户端发送消息类型

struct msgbuf          // 消息结构
{
    long mtype;     // 消息类型
    char mtext[MSGSIZE]; // 消息buf
};

int create_msg_queue();  // 创建消息队列
int destroy_msg_queue( int msg_que_id); // 销毁消息队列

int get_msg_queue();     // 获取消息队列

int send_msg( int msg_que_id, long type,  const char *_sendInfo);   // 发送消息
int recv_msg(int msg_que_id, long type, char buf[]);       // 接收消息

void *consumer(void *arg);
void *producer(void *arg);

#endif /* _COMMON_H*/
