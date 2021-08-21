//ѧ�ţ�2020217793 ��������t�� �༶�����ſ�20-1��
#include <iostream>
using namespace std;

#define MaxLen 100 //�������ܴ�ŵ������������
typedef int elementType;

typedef struct
{
    elementType data[MaxLen];
    int front; //ͷָ��
    int rear;  //βָ��
} seqQueue;    //����˳����еĴ洢�ṹ

void initial(seqQueue &Q) //��ʼ�����У�ͷβָ��ָ��0���ɣ�
{
    Q.front = 0;
    Q.rear = 0;
}

bool queueEmpty(seqQueue &Q) //�ж϶����Ƿ�Ϊ�գ�ͷβָ���Ƿ�ָ��ͬһλ�ã�
{
    if (Q.front == Q.rear)
    {

        return true;
    }
    else
        return false;
}

bool isFull(seqQueue &Q) //��������ע��ѭ�����е���������������
{
    if ((Q.rear + 1) % MaxLen == Q.front) //����������
    {
        cout << "��������" << endl;
        return true;
    }
    else
        return false;
}

void inQueue(seqQueue &Q, elementType x) //���
{
    if (!isFull(Q))
    {
        Q.rear = (Q.rear + 1) % MaxLen; //βָ��������
        Q.data[Q.rear] = x;
    }
}

void outQueue(seqQueue &Q) //����
{
    if (queueEmpty(Q)) //�п�
        cout << "����Ϊ��" << endl;
    else
    {
        Q.front = (Q.front + 1) % MaxLen; //ʹ��ͷָ�������һ��
    }
}

void getQueuefront(seqQueue &Q, elementType &x) //ȡ��ͷ
{
    if (queueEmpty(Q))
    {
        cout << "����Ϊ��" << endl;
    }
    else
        x = Q.data[(Q.front + 1) % MaxLen]; //ȡ����ͷ��Ԫ�ظ�ֵ��x����ͨ�����÷�ʽ����
}

int lenQueue(seqQueue Q) //������еĳ���
{
    return (Q.rear - Q.front + MaxLen) % MaxLen;
}

void printQueue(seqQueue Q) //���˳����е�����Ԫ��
{
    while (!queueEmpty(Q))
    {
        cout << Q.data[++Q.front] << " ";
    }
}
