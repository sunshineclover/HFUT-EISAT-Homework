//学号：2020217793 姓名：洪祎麟 班级：电信科20-1班
#include <iostream>
using namespace std;

typedef char elementType;
typedef struct lsNode
{
    elementType data;    //链栈结点数据域
    struct lsNode *next; //链栈结点指针域
} Node, *linkStack;      //一个节点的数据结构

linkStack createStack() //创建一个链栈（代码实现即是创建一个头结点）
{
    linkStack S;
    S = new Node;
    S->data = 0; //头结点数据表示栈内元素个数
    S->next = NULL;
    return S;
}

void pushStack(linkStack &S, elementType x) //入栈
{
    Node *t;
    t = new Node;
    t->data = x;
    t->next = S->next;
    S->next = t; //指针更改指向
}

elementType popStack(linkStack &S) //出栈
{
    if (S->next == NULL)
    {
        return -1;
    }
    else
    {
        elementType result;
        Node *t = S->next;
        result = t->data;
        S->next = t->next;
        delete t; //注意出栈后要释放节点
        return result;
    }
}