//ѧ�ţ�2020217793 ��������t�� �༶�����ſ�20-1��
#include <iostream>
using namespace std;

#define MaxLen 100       //˳������󳤶�
typedef int elementType; //elementType�ɸ�Ϊ��Ҫ�����Ԫ������
typedef struct sList
{
    elementType data[MaxLen]; //˳�������
    int listlen;              //˳����
} seqList;

void initial(seqList &L) //��ʼ��˳���(��������Ϊ0)
{
    L.listlen = 0;
}

void create(seqList &L) //����һ��˳���
{
    cout << "���������ݣ���-1Ϊ����" << endl;
    elementType x;
    cin >> x;
    while (L.listlen <= MaxLen && x != -1) //�������ݣ�Ϊ-1ʱ���� ���߱����˵�ʱ�����
    {
        L.data[L.listlen] = x;
        L.listlen++;
        cin >> x;
        if (x == -1)
            cout << "����˳���ɹ�" << endl;
    }
}

void insert0(seqList &L, elementType n, int i) //����һ��Ԫ�ص�������������
{
    if (L.listlen == MaxLen)
    {
        cout << "˳�������" << endl;
    }
    else if (i < 1 || i > L.listlen + 1)
    {
        cout << "���������Ų�����Ҫ��" << endl;
    }
    else
    {
        int j;
        for (j = L.listlen - 1; j >= i - 1; j--) //Ԫ��������һλ
        {
            L.data[j + 1] = L.data[j];
        }

        L.data[j + 1] = n; //����Ҫ�����Ԫ�طŹ�ȥ
        L.listlen++;
    }
}

void listDelete(seqList &L, int i) //ɾ�������һ��Ԫ��
{
    if (L.listlen <= 0)
        cout << "������ˣ�" << endl;
    else if (i < 1 || i > L.listlen)
        cout << "������������������������" << endl;
    else
    {
        int j;
        for (j = i; j <= L.listlen - 1; j++) //ɾ�����˺����Ԫ����ǰ��
            L.data[j - 1] = L.data[j];
        L.listlen--;
    }
}

void insert1(seqList &L, elementType x) //����һ��Ԫ��
{
    int i = L.listlen - 1;
    if (i >= MaxLen - 1)
        cout << "������" << endl;
    else
    {
        while (i >= 0 && L.data[i] > x) //����Ԫ�� �Ѻ������ǰ��
        {
            L.data[i + 1] = L.data[i];
            i--;
        }
        L.data[i + 1] = x;
        L.listlen++; //������ɺ��+1
    }
}

void mergeList(seqList &A, seqList &B, seqList &C) //������˳����Ԫ���ŵ�������˳�����
{
    int a = 1, b = 1, c = 1; //A��B��CԪ�ر�ţ���1��ʼ
    elementType x, y;
    while (a <= A.listlen && b <= B.listlen) //���������Ԫ�ض�û��ȫ�c��ʱ��ѭ��
    {
        x = A.data[a - 1];
        y = B.data[b - 1];
        if (x < y) //˭��Ԫ��С��˭��Ԫ�طŵ�c��
        {
            insert0(C, x, c);
            c++;
            a++;
        }
        else if (x == y)
        {
            insert0(C, x, c);
            c++;
            a++;
            b++;
        }
        else
        {
            insert0(C, y, c);
            c++;
            b++;
        }
    }
    while (a <= A.listlen) //��һ��������֮�󣬰���һ��˳��������Ԫ�طŵ��ܱ���
    {
        x = A.data[a - 1];
        insert0(C, x, c);
        c++;
        a++;
    }
    while (b <= B.listlen)
    {
        y = B.data[b - 1];
        insert0(C, y, c);
        c++;
        b++;
    }
}

void printList(seqList L) //���˳���
{
    for (int i = 0; i < L.listlen; i++)
    {
        cout << L.data[i] << " "; //�����ʱ����' '�ָ�һ��
    }
}

int main()
{
    seqList A, B, C;
    initial(A);
    initial(B);
    initial(C);
    elementType x;
    cout << "1.����" << endl;
    cout << "2.ɾ���" << endl;
    cout << "3.��Ԫ��" << endl;
    cout << "4.�����ϲ�" << endl;
    cout << "����������ִ�еĲ��������֣�" << endl;
    int a;
    cin >> a;
    switch (a)
    {
    case 1:
    {
        cout << "�봴��һ��˳���" << endl;
        create(A);
        cout << "������Ҫ����Ľ��λ�úͽ���ֵ" << endl;
        int i;
        cin >> i >> x;
        insert0(A, i, x); //�������
        printList(A);     //���˳���
        break;
    }
    case 2:
    {
        cout << "�봴��һ��˳���" << endl;
        create(A);
        cout << "��������Ҫɾ���Ľ�����" << endl;
        int i;
        cin >> i;
        listDelete(A, i); //ɾ������
        printList(A);     //���˳���
        break;
    }
    case 3:
    {
        cout << "�봴��һ��˳���" << endl;
        create(A);
        cout << "������Ҫ�������ֵ" << endl;
        cin >> x;
        insert1(A, x); //�������
        printList(A);  //���˳���
        break;
    }
    case 4:
    {
        cout << "�봴��һ��˳���" << endl;
        create(A);
        cout << "�봴����һ��˳���" << endl;
        create(B);
        mergeList(A, B, C); //�������
        printList(C);       //�����������˳���
        break;
    }
    }
    return 0;
}