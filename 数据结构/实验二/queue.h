//学号：2020217793 姓名：洪祎麟 班级：电信科20-1班
#include <iostream>
using namespace std;

#define MaxLen 100 //定义所能存放的最大数据数量
typedef int elementType;

typedef struct
{
    elementType data[MaxLen];
    int front; //头指针
    int rear;  //尾指针
} seqQueue;    //定义顺序队列的存储结构

void initial(seqQueue &Q) //初始化队列（头尾指针指向0即可）
{
    Q.front = 0;
    Q.rear = 0;
}

bool queueEmpty(seqQueue &Q) //判断队列是否为空（头尾指针是否指向同一位置）
{
    if (Q.front == Q.rear)
    {

        return true;
    }
    else
        return false;
}

bool isFull(seqQueue &Q) //判满：（注：循环队列的特殊判满方法）
{
    if ((Q.rear + 1) % MaxLen == Q.front) //判满的条件
    {
        cout << "队伍满了" << endl;
        return true;
    }
    else
        return false;
}

void inQueue(seqQueue &Q, elementType x) //入队
{
    if (!isFull(Q))
    {
        Q.rear = (Q.rear + 1) % MaxLen; //尾指针往后移
        Q.data[Q.rear] = x;
    }
}

void outQueue(seqQueue &Q) //出队
{
    if (queueEmpty(Q)) //判空
        cout << "队列为空" << endl;
    else
    {
        Q.front = (Q.front + 1) % MaxLen; //使得头指针向后移一个
    }
}

void getQueuefront(seqQueue &Q, elementType &x) //取队头
{
    if (queueEmpty(Q))
    {
        cout << "队列为空" << endl;
    }
    else
        x = Q.data[(Q.front + 1) % MaxLen]; //取出对头的元素赋值给x，并通过引用方式传走
}

int lenQueue(seqQueue Q) //计算队列的长度
{
    return (Q.rear - Q.front + MaxLen) % MaxLen;
}

void printQueue(seqQueue Q) //输出顺序队列的所有元素
{
    while (!queueEmpty(Q))
    {
        cout << Q.data[++Q.front] << " ";
    }
}
