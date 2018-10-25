#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include<pthread.h>
#include"head/bank_head.h"

REP_REQ_ST rep_req_st;

int main(int argc,char **argv)
{
    if(argc != 2)
    {
      printf("please input one arguement after command!");
	  return 0;
    }
    int counter_number;
    counter_number = atoi(argv[1]); //确定柜台号
    int customer_number;
	int fd;
	int len,ret;
	struct sockaddr_in remoteaddr;
	
    //
    // 建立套接口
    // 
    fd = socket(AF_INET, SOCK_STREAM, 0);
 
    //
    // 连接
    //
    remoteaddr.sin_family = AF_INET;
    remoteaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    remoteaddr.sin_port = htons(5000);
    len = sizeof(remoteaddr);

    ret = connect(fd, (struct sockaddr *)&remoteaddr, len);
    if(ret == -1) 
    {
       printf("connect() error\n");
       return -1;
    }

   //发送银行柜台信号
   rep_req_st.sign_type = IS_BANK_COUNT;
   ret = send(fd,&rep_req_st, sizeof(REP_REQ_ST),0);
   if(ret <= 0)
   {
	   printf("send() error\n");
   }
   while(1)
   {				
	    sleep(1);
		//获取顾客号码
		ret = recv(fd, &customer_number , sizeof(int), 0);
		if(ret <= 0)
		{
			printf("server recieve data failed!--\n");
		} 
		else
		{
			printf("please customer %d come to counter %d\n", customer_number,counter_number); 
		}
		sleep(5);//模拟业务处理时间

		
		/***********************************
               *发送顾客业务处理完毕信号
               *模拟柜台服务员删号
		************************************/
		rep_req_st.sign_type = IS_CLIENT_END;
		send(fd, &rep_req_st, sizeof(REP_REQ_ST),0);		
		
	}
    
 
   
finish: 
    close(fd);  
    return 0;
}

