//ѧ�ţ�2020217793 ��������t�� �༶�����ſ�20-1��
#include "link.h"
int main()
{
    linkQueue Q;
    initialQueue(Q);
    elementType x;
    cout << "1.��ʼ��" << endl;
    cout << "2.�ж϶ӿ�" << endl;
    cout << "3.���" << endl;
    cout << "4.����" << endl;
    cout << "5.ȡ��ͷ" << endl;
    cout << "6.�󳤶�" << endl;
    cout << "7.һϵ�в���" << endl;
    cout << "����������ִ�еĲ��������֣�" << endl;
    int a;
    cin >> a;
    switch (a)
    {
    case 1:
        initialQueue(Q); //1.��ʼ��
        break;
    case 2:
        cout << QueueEmpty(Q) << endl; //2.�ж϶ӿ�
        break;
    case 3:
        inQueue(Q, x); //3.���
        break;
    case 4:
        outQueue(Q); //4.����
        break;
    case 5:
        getQueuehead(Q, x); //5.ȡ��ͷ
        break;
    case 6:
    {
        int l = getQueuelen(Q);
        cout << "����Ϊ" << l << endl; //6.�󳤶�
        break;
    }
    case 7:
    {
        cout << "�뿪ʼ����Ԫ�أ���0Ϊ��������0���ڶ���֮�У�" << endl;
        elementType x;
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
        int length = getQueuelen(Q); //��ӳ�
        cout << "���еĳ���Ϊ:" << length << endl;
    }
    }
    return 0;
}