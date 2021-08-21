//学号：2020217793 姓名：洪祎麟 班级：电信科20-1班
#include <iostream>
using namespace std;
typedef int elementType;

typedef struct Node
{
    elementType data;
    struct Node *next;
} node; //一个节点

typedef struct Queue
{
    node *front;
    node *rear;
} linkQueue; //链队列的数据结构 一个头指针一个尾指针

void initialQueue(linkQueue &Q) //初始化队列（建立头结点）
{
    Q.front = new node;
    Q.front->next = NULL;
    Q.rear = Q.front;
}

bool QueueEmpty(linkQueue Q) //判断队列是否为空
{
    if (Q.front == Q.rear)
    {
        cout << "队列是空的" << endl;
        return true;
    }
    else
        return false;
}

void inQueue(linkQueue &Q, elementType x) //入队 将元素插入最后
{
    node *t;
    t = new node;
    t->data = x;
    t->next = NULL;
    Q.rear->next = t;
    Q.rear = t;
}

void outQueue(linkQueue &Q) //出队，改变指针指向完成
{
    if (!QueueEmpty(Q))
    {
        Q.front->next = Q.front->next->next;
        if (Q.front->next == NULL)
        {
            Q.rear = Q.front;
        }
    }
}

int getQueuelen(linkQueue Q) //获得队列长度
{
    int cnt = 0;
    for (node *p = Q.front; p != Q.rear; p = p->next)
        cnt++;
    return cnt;
}

void getQueuehead(linkQueue Q, elementType &x) //取队头
{
    if (!QueueEmpty(Q))
        x = Q.front->next->data;
}

void printQueue(linkQueue &Q) //输出队列
{
    for (node *t = Q.front; t != Q.rear; t = t->next)
        cout << t->next->data << ' ';
}