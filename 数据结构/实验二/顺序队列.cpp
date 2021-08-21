//学号：2020217793 姓名：洪祎麟 班级：电信科20-1班
#include "queue.h"
int main()
{
    seqQueue Q;
    initial(Q); //初始化顺序表
    elementType x;
    cout << "1.初始化" << endl;
    cout << "2.判断队空" << endl;
    cout << "3.判断队满" << endl;
    cout << "4.入队" << endl;
    cout << "5.出队" << endl;
    cout << "6.取队头" << endl;
    cout << "7.求长度" << endl;
    cout << "8.一系列操作" << endl;
    cout << "请输入你想执行的操作（数字）" << endl;
    int a;
    cin >> a;
    switch (a)
    {
    case 1:
        initial(Q); //1.初始化
        break;
    case 2:
        cout << queueEmpty(Q) << endl; //2.判断队空
        break;
    case 3:
        cout << isFull(Q) << endl; //3.判断队满
        break;
    case 4:
        inQueue(Q, x); //4.入队
        break;
    case 5:
        outQueue(Q); //5.出队
        break;
    case 6:
        getQueuefront(Q, x); //6.取队头
        break;
    case 7:
    {
        int l = lenQueue(Q);
        cout << "长度为" << l << endl; //7.求长度
        break;
    }
    case 8:
    {
        cout << "请开始输入元素，输入0即为退出输入（0并不在队列中）" << endl;
        cin >> x;
        while (x != 0)
        {
            if (x % 2)
            {
                inQueue(Q, x); //奇数入队
            }
            else
            {
                outQueue(Q); //偶数出队
            }
            printQueue(Q);

            cin >> x;
        }
        int l = lenQueue(Q); //求出队伍长度
        cout << "队列的长度为" << l << endl;

        break;
    }
    }

    return 0;
}