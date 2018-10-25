#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include"head/bank_head.h"
#include<sys/stat.h>
#include<fcntl.h> 

#define savefile "./savefile.txt"

REP_REQ_ST rep_req_st;
int g_curent_num,g_i;


/**********************
 *函数名:取号机用户界面函数
 *功能:生成面向顾客的界面
 *打印当前顾客号码和查询
 *当前业务办理人数即等待
 *人数
 *返回值:当前取号顾客的号码
 ***********************/
int GetNumberUserMenu(int arg)
{
  int n;
 
  if(g_i == 5)
  {
    g_curent_num = 1;
	g_i++;
  } 
loop1:  printf("\n******************************welcom to ICBC**********************\n");
  printf("                              1    customer get number and see the queue\n");                          
  printf("                              2    exit\n");
  CurentTime();
  printf("*******************************************************************\n");
  printf("please input : ");
  scanf("%d",&n);
  
  switch(n)
  	{
     case 1:
		 printf("\n*****************customer get number interface***********************\n\n"); 
		 printf("your server number is %d.\n",++g_curent_num);		
		 printf("there are %d people in front of you!\n",arg);
		 sleep(1);
         system("clear");
		 return(g_curent_num);
		 break;
	 case 2:
	 	 return 0;

	 default :

	 	 break;	 	 
     
    }
  return(0);
}



int main(int argc,char **argv)
{
	int fd,first_customer;
	int len,ret,recvnum,GNUM_ARG = 0;
	struct sockaddr_in remoteaddr;
	char data[1024];
	int send_number;

	
	
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
	g_i = 5;
	
    //发送取号机信号
	rep_req_st.sign_type = IS_GET_NUMBER;
    ret = send(fd, &rep_req_st, sizeof(REP_REQ_ST),0);
	
	while(1)
	{
	    if(g_i == 5)
	    {
		  printf("\n******************************welcom to ICBC**********************\n");
		  printf("                              1    customer get number and see the queue\n");                          
		  CurentTime();
		  printf("*******************************************************************\n");
		  printf("please input : ");
		  scanf("%d",&first_customer);
		  send_number = 1;
		  system("clear");
		}
	    
		printf("currentt number:%d\n",send_number);
		//发送顾客号码给服务器
		ret = send(fd, &send_number, sizeof(int),0);
		if(ret <= 0)
		{
		   printf("send() error\n");
		}
		ret = recv(fd,&recvnum, sizeof(REP_REQ_ST), 0);
		GNUM_ARG = recvnum;
		
		//顾客用户界面
        send_number = GetNumberUserMenu(GNUM_ARG);
		
	}
	close(fd);
	return 0;
}

