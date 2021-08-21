//学号：2020217793 姓名：洪祎麟 班级：电信科20-1班
#include <iostream>
using namespace std;

#define MaxLen 100       //顺序表的最大长度
typedef int elementType; //elementType可改为需要满足的元素类型
typedef struct sList
{
    elementType data[MaxLen]; //顺序表数据
    int listlen;              //顺序表表长
} seqList;

void initial(seqList &L) //初始化顺序表(即长度设为0)
{
    L.listlen = 0;
}

void create(seqList &L) //创造一个顺序表
{
    cout << "请输入数据，以-1为结束" << endl;
    elementType x;
    cin >> x;
    while (L.listlen <= MaxLen && x != -1) //输入数据：为-1时结束 或者表长满了的时候结束
    {
        L.data[L.listlen] = x;
        L.listlen++;
        cin >> x;
        if (x == -1)
            cout << "创造顺序表成功" << endl;
    }
}

void insert0(seqList &L, elementType n, int i) //插入一个元素到所输入的序号中
{
    if (L.listlen == MaxLen)
    {
        cout << "顺序表已满" << endl;
    }
    else if (i < 1 || i > L.listlen + 1)
    {
        cout << "您输入的序号不符合要求" << endl;
    }
    else
    {
        int j;
        for (j = L.listlen - 1; j >= i - 1; j--) //元素往后移一位
        {
            L.data[j + 1] = L.data[j];
        }

        L.data[j + 1] = n; //把需要插入的元素放过去
        L.listlen++;
    }
}

void listDelete(seqList &L, int i) //删除链表的一个元素
{
    if (L.listlen <= 0)
        cout << "下溢出了！" << endl;
    else if (i < 1 || i > L.listlen)
        cout << "您输入的序号有误，请重新输入" << endl;
    else
    {
        int j;
        for (j = i; j <= L.listlen - 1; j++) //删除完了后面的元素往前移
            L.data[j - 1] = L.data[j];
        L.listlen--;
    }
}

void insert1(seqList &L, elementType x) //插入一个元素
{
    int i = L.listlen - 1;
    if (i >= MaxLen - 1)
        cout << "表满了" << endl;
    else
    {
        while (i >= 0 && L.data[i] > x) //插入元素 把后面的往前移
        {
            L.data[i + 1] = L.data[i];
            i--;
        }
        L.data[i + 1] = x;
        L.listlen++; //插入完成后表长+1
    }
}

void mergeList(seqList &A, seqList &B, seqList &C) //将两个顺序表的元素排到第三个顺序表中
{
    int a = 1, b = 1, c = 1; //A、B、C元素编号，从1开始
    elementType x, y;
    while (a <= A.listlen && b <= B.listlen) //当两个表的元素都没完全填到c的时候循环
    {
        x = A.data[a - 1];
        y = B.data[b - 1];
        if (x < y) //谁的元素小把谁的元素放到c中
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
    while (a <= A.listlen) //当一个完事了之后，把另一个顺序表的所有元素放到总表中
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

void printList(seqList L) //输出顺序表
{
    for (int i = 0; i < L.listlen; i++)
    {
        cout << L.data[i] << " "; //输出的时候用' '分隔一下
    }
}

int main()
{
    seqList A, B, C;
    initial(A);
    initial(B);
    initial(C);
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
        cout << "请创建一个顺序表" << endl;
        create(A);
        cout << "请输入要插入的结点位置和结点的值" << endl;
        int i;
        cin >> i >> x;
        insert0(A, i, x); //插入操作
        printList(A);     //输出顺序表
        break;
    }
    case 2:
    {
        cout << "请创建一个顺序表" << endl;
        create(A);
        cout << "请输入需要删除的结点序号" << endl;
        int i;
        cin >> i;
        listDelete(A, i); //删除操作
        printList(A);     //输出顺序表
        break;
    }
    case 3:
    {
        cout << "请创建一个顺序表" << endl;
        create(A);
        cout << "请输入要插入结点的值" << endl;
        cin >> x;
        insert1(A, x); //插入操作
        printList(A);  //输出顺序表
        break;
    }
    case 4:
    {
        cout << "请创建一个顺序表" << endl;
        create(A);
        cout << "请创建另一个顺序表" << endl;
        create(B);
        mergeList(A, B, C); //整理操作
        printList(C);       //输出整理过后的顺序表
        break;
    }
    }
    return 0;
}