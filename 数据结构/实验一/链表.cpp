//ѧ�ţ�2020217793 ��������t�� �༶�����ſ�20-1��
#include <iostream>
using namespace std;

typedef int elementType;
typedef struct LNode
{
    elementType data;
    struct LNode *next;
} node, *linkList; //����Ľڵ�ṹ

node *initiallist() //��ʼ���������Ǵ���ͷ���
{
    node *p;
    p = new node;
    p->next = NULL;
    return p;
}

int lenList(node *&L) //�������ĳ���
{
    int cnt = 0;
    for (node *t = L; t->next; t = t->next)
        cnt++;
    return cnt;
}

void createlist(node *&L) //����һ��������
{
    node *R = L;
    cout << "��������������ݣ�-1Ϊֹ" << endl;
    elementType x;
    cin >> x;
    while (x != -1) //-1Ϊ�ж�Ԫ���Ƿ�������ϵı�ʶ
    {
        node *u;
        u = new node;
        u->data = x;
        R->next = u;
        R = u;
        cin >> x;
    }
    R->next = NULL;
}

void printList(node *&L) //����õ�����
{
    for (node *t = L->next; t->next; t = t->next)
        cout << t->next->data << " ";
}

void insert0(node *&L, int i, elementType x) //�������в���Ԫ�أ�������ȷλ��
{
    node *p;
    p = new node;
    p = L->next;
    int j = 1;
    if (i > lenList(L) + 1 || i < 1)
    {
        cout << "��������������" << endl;
    }
    else
    {
        while ((j != i - 1) && (p != NULL)) //����������ֱ������׼ȷ��λ��
        {
            p = p->next;
            j++;
        }
        if (j == i - 1) //����λ�ú�ͨ���ı�ָ��ָ����������
        {
            node *t = new node;
            t->next = p->next;
            t->data = x;
            p->next = t;
            cout << "����ɹ�" << endl;
        }
        else
            cout << "����ʧ��" << endl;
        delete p;
    }
}

void listDelete(node *&L, int i) //��յ������һ��λ���ϵ�Ԫ��
{
    node *u;
    node *p = L;
    int k = 0;
    if (i > lenList(L) || i < 1)
    {
        cout << "��������������" << endl;
    }
    else
    {
        while (k != i - 1 && p != NULL) //����ָ��λ�ú�Ԫ�����
        {
            p = p->next;
            k++;
        }
        u = p->next;
        p->next = u->next;
        delete u;
    }
}

void insert1(node *&L, elementType x) //�������в���Ԫ��
{
    int j = 1;
    int flag = 0;
    int cnt = 0;
    node *q = L->next;
    while (q)
    {
        if (cnt == 0 && q->data > x) //�ҵ���ȷ����λ�ü��ɽ��в��� 1.��������ǰ��
        {
            node *t = new node;
            t->next = q;
            t->data = x;
            L->next = t;
            flag = 1;
            cout << "����ɹ�" << endl;
            break;
        }
        else if (q->next != NULL) //2.�������м�
        {
            if (q->data <= x && q->next->data >= x)
            {
                node *t = new node;
                t->next = q->next;
                t->data = x;
                q->next = t;
                flag = 1;
                cout << "����ɹ�" << endl;
                break;
            }
        }
        else //3.���������
        {
            node *t = new node;
            t->next = q->next;
            t->data = x;
            q->next = t;
            flag = 1;
            cout << "����ɹ�" << endl;
            break;
        }
        q = q->next;
        cnt++;
        cout << q->data << endl;
    }
    if (flag == 0)
        cout << "����ʧ��" << endl;
}

void mergeList(node *&A, node *&B, node *&C) //���������Ԫ�غϵ�������������
{
    node *t = C;
    while (A && B)
    {
        if (A->data < B->data) //�ж����������е�ǰԪ�صĴ�С����C����ָ�����е�С��
        {
            t->next = A;
            t = A;
            A = A->next;
        }
        else if (A->data == B->data)
        {
            t->next = A;
            t = A;
            A = A->next;
            B = B->next;
        }
        else if (A->data > B->data)
        {
            t->next = B;
            t = B;
            B = B->next;
        }
    }
    if (A) //һ���������º������ֱ�ӽ�C����ָ����һ��δ���µ�����
    {
        t->next = A;
    }
    if (B)
    {
        t->next = B;
    }
}

int main()
{
    linkList A, B, C;
    A = initiallist();
    B = initiallist();
    C = initiallist();

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
        cout << "�봴��һ������" << endl;
        createlist(A); //��������
        cout << "������Ҫ����Ľ��λ�úͽ���ֵ" << endl;
        int i;
        cin >> i >> x;
        insert0(A, i, x); //����Ԫ��
        printList(A);     //�������
        break;
    }
    case 2:
    {
        cout << "�봴��һ������" << endl;
        createlist(A); //��������
        cout << "��������Ҫɾ���Ľ�����" << endl;
        int i;
        cin >> i;
        listDelete(A, i); //ɾ��Ԫ��
        printList(A);     //�������
        break;
    }
    case 3:
    {
        cout << "�봴��һ������" << endl;
        createlist(A); //��������
        cout << "������Ҫ�������ֵ" << endl;
        cin >> x;
        insert1(A, x); //����Ԫ��
        printList(A);  //�������
        break;
    }
    case 4:
    {
        cout << "�봴��һ������" << endl;
        createlist(A);
        cout << "�봴����һ������" << endl;
        createlist(B);
        mergeList(*&A, *&B, *&C);
        printList(C);
        break;
    }
    }
    return 0;
}