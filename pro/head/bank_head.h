#ifndef _BANK_HEAD_H
#define _BANK_HEAD_H

#include <time.h>
#include<stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include<pthread.h>
#include<string.h>
#include<time.h>



#define IS_GET_NUMBER 1
#define IS_BANK_COUNT 2
#define IS_CLIENT_END 3
#define QElemType int




/*定义一个结构体
用来server响应不同
客户端的请求*/
typedef struct ReplayDifferentRequest
{
  long sign_type;
}REP_REQ_ST;

//全局变量
REP_REQ_ST rep_req_st;




/*******************
*函数的声明
*
********************/
void DeleteFirstEle(char *a);
void InitRDRSt(void);
void CurentTime(void);


#endif


