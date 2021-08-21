//ѧ�ţ�2020217793 ��������t�� �༶�����ſ�20-1��
#include <iostream>
using namespace std;
typedef int elementType;

typedef struct Node
{
    elementType data;
    struct Node *next;
} node; //һ���ڵ�

typedef struct Queue
{
    node *front;
    node *rear;
} linkQueue; //�����е����ݽṹ һ��ͷָ��һ��βָ��

void initialQueue(linkQueue &Q) //��ʼ�����У�����ͷ��㣩
{
    Q.front = new node;
    Q.front->next = NULL;
    Q.rear = Q.front;
}

bool QueueEmpty(linkQueue Q) //�ж϶����Ƿ�Ϊ��
{
    if (Q.front == Q.rear)
    {
        cout << "�����ǿյ�" << endl;
        return true;
    }
    else
        return false;
}

void inQueue(linkQueue &Q, elementType x) //��� ��Ԫ�ز������
{
    node *t;
    t = new node;
    t->data = x;
    t->next = NULL;
    Q.rear->next = t;
    Q.rear = t;
}

void outQueue(linkQueue &Q) //���ӣ��ı�ָ��ָ�����
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

int getQueuelen(linkQueue Q) //��ö��г���
{
    int cnt = 0;
    for (node *p = Q.front; p != Q.rear; p = p->next)
        cnt++;
    return cnt;
}

void getQueuehead(linkQueue Q, elementType &x) //ȡ��ͷ
{
    if (!QueueEmpty(Q))
        x = Q.front->next->data;
}

void printQueue(linkQueue &Q) //�������
{
    for (node *t = Q.front; t != Q.rear; t = t->next)
        cout << t->next->data << ' ';
}