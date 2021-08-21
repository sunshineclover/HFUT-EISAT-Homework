//ѧ�ţ�2020217793 ��������t�� �༶�����ſ�20-1��
#include <iostream>
using namespace std;

typedef char elementType;
typedef struct lsNode
{
    elementType data;    //��ջ���������
    struct lsNode *next; //��ջ���ָ����
} Node, *linkStack;      //һ���ڵ�����ݽṹ

linkStack createStack() //����һ����ջ������ʵ�ּ��Ǵ���һ��ͷ��㣩
{
    linkStack S;
    S = new Node;
    S->data = 0; //ͷ������ݱ�ʾջ��Ԫ�ظ���
    S->next = NULL;
    return S;
}

void pushStack(linkStack &S, elementType x) //��ջ
{
    Node *t;
    t = new Node;
    t->data = x;
    t->next = S->next;
    S->next = t; //ָ�����ָ��
}

elementType popStack(linkStack &S) //��ջ
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
        delete t; //ע���ջ��Ҫ�ͷŽڵ�
        return result;
    }
}