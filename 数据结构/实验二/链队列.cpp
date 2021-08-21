//学号：2020217793 姓名：洪祎麟 班级：电信科20-1班
#include "link.h"
int main()
{
    linkQueue Q;
    initialQueue(Q);
    elementType x;
    cout << "1.初始化" << endl;
    cout << "2.判断队空" << endl;
    cout << "3.入队" << endl;
    cout << "4.出队" << endl;
    cout << "5.取队头" << endl;
    cout << "6.求长度" << endl;
    cout << "7.一系列操作" << endl;
    cout << "请输入你想执行的操作（数字）" << endl;
    int a;
    cin >> a;
    switch (a)
    {
    case 1:
        initialQueue(Q); //1.初始化
        break;
    case 2:
        cout << QueueEmpty(Q) << endl; //2.判断队空
        break;
    case 3:
        inQueue(Q, x); //3.入队
        break;
    case 4:
        outQueue(Q); //4.出队
        break;
    case 5:
        getQueuehead(Q, x); //5.取队头
        break;
    case 6:
    {
        int l = getQueuelen(Q);
        cout << "长度为" << l << endl; //6.求长度
        break;
    }
    case 7:
    {
        cout << "请开始输入元素，以0为结束。（0不在队列之中）" << endl;
        elementType x;
        cin >> x;
        while (x != 0)
        {
            if (x % 2)
            {
                inQueue(Q, x); //奇数入队
            }
            else
            {
                outQueue(Q); //偶数出对
            }
            printQueue(Q);
            cin >> x;
        }
        int length = getQueuelen(Q); //求队长
        cout << "队列的长度为:" << length << endl;
    }
    }
    return 0;
}