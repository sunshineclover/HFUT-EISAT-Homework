//学号：2020217793 姓名：洪祎麟 班级：电信科20-1班
#include <iostream>
using namespace std;

typedef int elementType;
typedef struct LNode
{
    elementType data;
    struct LNode *next;
} node, *linkList; //链表的节点结构

node *initiallist() //初始化链表：即是创建头结点
{
    node *p;
    p = new node;
    p->next = NULL;
    return p;
}

int lenList(node *&L) //求出链表的长度
{
    int cnt = 0;
    for (node *t = L; t->next; t = t->next)
        cnt++;
    return cnt;
}

void createlist(node *&L) //创建一个单链表
{
    node *R = L;
    cout << "请输入链表的数据，-1为止" << endl;
    elementType x;
    cin >> x;
    while (x != -1) //-1为判断元素是否输入完毕的标识
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

void printList(node *&L) //输出该单链表
{
    for (node *t = L->next; t->next; t = t->next)
        cout << t->next->data << " ";
}

void insert0(node *&L, int i, elementType x) //向单链表中插入元素，放入正确位置
{
    node *p;
    p = new node;
    p = L->next;
    int j = 1;
    if (i > lenList(L) + 1 || i < 1)
    {
        cout << "您输入的序号有误" << endl;
    }
    else
    {
        while ((j != i - 1) && (p != NULL)) //遍历单链表直至到达准确的位置
        {
            p = p->next;
            j++;
        }
        if (j == i - 1) //到达位置后通过改变指针指向，来插入结点
        {
            node *t = new node;
            t->next = p->next;
            t->data = x;
            p->next = t;
            cout << "插入成功" << endl;
        }
        else
            cout << "插入失败" << endl;
        delete p;
    }
}

void listDelete(node *&L, int i) //清空单链表的一个位置上的元素
{
    node *u;
    node *p = L;
    int k = 0;
    if (i > lenList(L) || i < 1)
    {
        cout << "您输入的序号有误" << endl;
    }
    else
    {
        while (k != i - 1 && p != NULL) //到达指定位置后将元素清空
        {
            p = p->next;
            k++;
        }
        u = p->next;
        p->next = u->next;
        delete u;
    }
}

void insert1(node *&L, elementType x) //向单链表中插入元素
{
    int j = 1;
    int flag = 0;
    int cnt = 0;
    node *q = L->next;
    while (q)
    {
        if (cnt == 0 && q->data > x) //找到了确定的位置即可进行插入 1.插入在最前面
        {
            node *t = new node;
            t->next = q;
            t->data = x;
            L->next = t;
            flag = 1;
            cout << "插入成功" << endl;
            break;
        }
        else if (q->next != NULL) //2.插入在中间
        {
            if (q->data <= x && q->next->data >= x)
            {
                node *t = new node;
                t->next = q->next;
                t->data = x;
                q->next = t;
                flag = 1;
                cout << "插入成功" << endl;
                break;
            }
        }
        else //3.插入在最后
        {
            node *t = new node;
            t->next = q->next;
            t->data = x;
            q->next = t;
            flag = 1;
            cout << "插入成功" << endl;
            break;
        }
        q = q->next;
        cnt++;
        cout << q->data << endl;
    }
    if (flag == 0)
        cout << "插入失败" << endl;
}

void mergeList(node *&A, node *&B, node *&C) //两个链表的元素合到第三个链表中
{
    node *t = C;
    while (A && B)
    {
        if (A->data < B->data) //判断两个链表中当前元素的大小。让C链表指向其中的小者
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
    if (A) //一个链表完事后则可以直接将C链表指向另一个未完事的链表
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
    cout << "1.插结点" << endl;
    cout << "2.删结点" << endl;
    cout << "3.插元素" << endl;
    cout << "4.两个合并" << endl;
    cout << "请输入你想执行的操作（数字）" << endl;
    int a;
    cin >> a;
    switch (a)
    {
    case 1:
    {
        cout << "请创建一个链表" << endl;
        createlist(A); //创建链表
        cout << "请输入要插入的结点位置和结点的值" << endl;
        int i;
        cin >> i >> x;
        insert0(A, i, x); //插入元素
        printList(A);     //输出链表
        break;
    }
    case 2:
    {
        cout << "请创建一个链表" << endl;
        createlist(A); //创建链表
        cout << "请输入需要删除的结点序号" << endl;
        int i;
        cin >> i;
        listDelete(A, i); //删除元素
        printList(A);     //输出链表
        break;
    }
    case 3:
    {
        cout << "请创建一个链表" << endl;
        createlist(A); //创建链表
        cout << "请输入要插入结点的值" << endl;
        cin >> x;
        insert1(A, x); //插入元素
        printList(A);  //输出链表
        break;
    }
    case 4:
    {
        cout << "请创建一个链表" << endl;
        createlist(A);
        cout << "请创建另一个链表" << endl;
        createlist(B);
        mergeList(*&A, *&B, *&C);
        printList(C);
        break;
    }
    }
    return 0;
}