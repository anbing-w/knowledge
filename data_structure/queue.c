#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _CIRCULAR_QUEUES__

#ifdef _SEQUENTIAL_QUEUES__

//结点定义
typedef struct node
{
    int data; //
    struct node *next; //
}node;

//队列定义，队首指针和队尾指针
typedef struct queue
{
    node *front; //头指针
    node *rear; //尾指针
}queue;

/**
 * @brief 初始化结点
 * 
 * @return node* 
 */
node *init_node()
{
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        exit(0);
    }
    return n;
}

//初始化队列
queue *init_queue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    if (q == NULL)
    {//创建失败，退出
        exit(0);
    }
    //头尾结点均赋值NULL
    q->front = NULL;
    q->rear = NULL;
    return q;
}

//队列判空
int empty(queue *q)
{
    if (q->front == NULL)
    {
        return 1;//1--表示真，说明队列空
    }
    else
    {
        return 0;//0--表示假，说明队列非空
    }
}

//返回值判断
/*
int empty(queue *q)
{
    return q-front == NULL;
}
*/

/**
 * @brief 入队操作
 * 
 * @param q 操作的队列
 * @param data 插入的值
 */
void push(queue *q, int data)
{
    node *n = init_node();
    n->data = data;
    n->next = NULL;
    if (empty(q))
    {//特判，队列为空，首尾结点都得指向这个结点
        q->front = n;
        q->rear = n;
    }
    else
    {
        q->rear->next = n; //n成为当前尾结点的下一个结点
        q->rear = n; //让尾指针指向n
    }
    
}
//出队操作
void pop(queue *q) 
{
    node *n = q->front;
    if (empty(q))
    {
        return ; //此时队列为空，直接返回函数结束
    }
    
    if (q->front == q->rear)
    {
        q->front = NULL; //只有一个元素时直接将两端指向置空
        q->rear = NULL; //
        free(q); //归还内存空间
    }
    else
    {
        q->front = q->front->next;
        free(n);
    }
    
}
//打印队列元素
void print_queue(queue *q)
{
    node *n = init_node();
    n = q->front;
    if(empty(q))
    {
        return; //队列为空，直接返回
    }
    while(n != NULL)
    {
        printf("%d\n",n->data);
        n = n->next;
    }
    printf("\n");
}

//计算队列中含有多少元素
int calculate_queue(queue *q)
{
    int cnt = 0;
    node *n = init_node(); 
    n = q->front;
    if (empty(q))   
    {
        return 0;
    }
    while (q != 0)
    {
        n = n->next;
        cnt++;
    }
    return cnt;
}

#endif



#ifdef _CIRCULAR_QUEUES__
#define MAX_QUEUE_SIZE 10 //循环队列的最大容量、

//循环队列的结构操作
typedef struct cir_queue
{
    int data[MAX_QUEUE_SIZE];
    int rear;
    int front;
}cir_queue;


//初始化
cir_queue *init()
{
    cir_queue *q = (cir_queue *)malloc(sizeof(cir_queue));
    if (NULL == q) 
    {
        exit(0); //申请内存失败，直接退出
    }
    q->front = 0;
    q->rear = 0;
}
//入队操作
void push(cir_queue *q, int data)
{
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front)
    {
        printf("溢出,无法入队\n");
        return;
    }
    else
    {
        q->rear = (q->front + 1) % MAX_QUEUE_SIZE;
        q->data[q->rear] = data;
    }
}
//出队操作
void pop(cir_queue *q)
{
    if (q->rear == q->front)
    {
        printf("队列为空，无法出队\n");
        return ;
    }
    else
    {
        q->data[q->front] = 0;
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    
}

//遍历操作
void print_queue(cir_queue *q)
{
    int i = q->front;
    while (i != q->rear)
    {
        i = (i + 1) % MAX_QUEUE_SIZE;
        printf("%d\t",q->data[i]);
    }
    printf("\n");
}

#endif