#include"bank_head.h"

/********************
*定义一个队列节点结构体
*储存客户的信息
*********************/
typedef struct QNode{
	QElemType data;
	struct QNode *next;
} QNode,*QueuePtr;

/*******************
*队列结构体
*
*********************/
struct Link
{
	QueuePtr front;
	QueuePtr rear;
}Queue,*Q;



/************
*各种函数的定义
*
**************/

//结构体初始化
void InitRDRSt()
{
   rep_req_st.sign_type = 0;
}


//显示当前时间
void CurentTime()
{
	time_t timep;
	time(&timep);
	printf("                   NOW TIME: %s",ctime(&timep));
}

void DeleteFirstEle(char *g)
{
  int i;
  for(i = 0;i < strlen(g)-1;i++)
  {
    g[i] = g[i+1];
	
  }
  g[strlen(g)-1] = 0;

}

/*
//创建队列
void CreateQueue(struct Link* Q)
{   
    int a;
	a = 0;
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
    Q = (struct Link*)malloc(sizeof(struct Link));
	if(!p)
	{
	   printf("create fail！");
    }
	else 
	{
	   p->next = NULL;
	   Q->front = p;
	     //printf("333333333444444443333\n");
	   Q->rear = p;
	   
	   p = (QueuePtr)malloc(sizeof(QNode));
	   p->next = NULL;
	   
	   if(!p) 
	   {
	      printf("create fail！") ;
	   }
	   else
	   {  
		  p->data = a;
          Q->rear->next = p;	
          Q->rear = p;		    
	   }
     }
}

//打印队列元素
void PrintfQueue(struct Link* Q)
{
    QueuePtr p;
	Q = (struct Link*)malloc(sizeof(struct Link));
	printf("正在办理业务的客户号码是:\n");
	for(p = Q->front->next; p != NULL; p = p->next)
    {
	   printf("customer:%d\n",p->data);
    }	
}
//入队列函数
void EnQueue(struct Link *Q,QElemType x)
{
     QueuePtr p;
	 p = (QueuePtr)malloc(sizeof(QNode));
	 Q = (struct Link*)malloc(sizeof(struct Link));
	 if(!p)
	 {
	    printf("create fail") ;
	 }
	 else
	 {
	    p->data=x;
		p->next=NULL;
		p = (QueuePtr)malloc(sizeof(QNode));
		Q->rear->next = p;
		Q->rear=p;
	 }
}

//出队列函数
void DeQueue(struct Link *Q,QElemType *f)
{  
    QueuePtr p;
	if(Q->front == Q->rear)  
		printf("\nError");
	else 
	{    
	    p = Q->front->next;
		*f = p->data;
		Q->front->next = p->next;
		
		if(Q->rear == p)
			Q->rear = Q->front;
		
		free(p);
	}
}

//判断队列是否为空
int QueueEmpty(struct Link Q)  

 {  

    if(Q.front != NULL && Q.rear != NULL)  
    {
        if(Q.front == Q.rear)  
        return 0;  

        else 
        return 1; 
    }

 }  

*/

/*****************************
*取号机用户界面函数
*功能:1. 取得号码
*             2. 查询当前排队情况
******************************/








