//ѧ�ţ�2020217793 ��������t�� �༶�����ſ�20-1��
#include "queue.h"
int main()
{
    seqQueue Q;
    initial(Q); //��ʼ��˳���
    elementType x;
    cout << "1.��ʼ��" << endl;
    cout << "2.�ж϶ӿ�" << endl;
    cout << "3.�ж϶���" << endl;
    cout << "4.���" << endl;
    cout << "5.����" << endl;
    cout << "6.ȡ��ͷ" << endl;
    cout << "7.�󳤶�" << endl;
    cout << "8.һϵ�в���" << endl;
    cout << "����������ִ�еĲ��������֣�" << endl;
    int a;
    cin >> a;
    switch (a)
    {
    case 1:
        initial(Q); //1.��ʼ��
        break;
    case 2:
        cout << queueEmpty(Q) << endl; //2.�ж϶ӿ�
        break;
    case 3:
        cout << isFull(Q) << endl; //3.�ж϶���
        break;
    case 4:
        inQueue(Q, x); //4.���
        break;
    case 5:
        outQueue(Q); //5.����
        break;
    case 6:
        getQueuefront(Q, x); //6.ȡ��ͷ
        break;
    case 7:
    {
        int l = lenQueue(Q);
        cout << "����Ϊ" << l << endl; //7.�󳤶�
        break;
    }
    case 8:
    {
        cout << "�뿪ʼ����Ԫ�أ�����0��Ϊ�˳����루0�����ڶ����У�" << endl;
        cin >> x;
        while (x != 0)
        {
            if (x % 2)
            {
                inQueue(Q, x); //�������
            }
            else
            {
                outQueue(Q); //ż������
            }
            printQueue(Q);

            cin >> x;
        }
        int l = lenQueue(Q); //������鳤��
        cout << "���еĳ���Ϊ" << l << endl;

        break;
    }
    }

    return 0;
}