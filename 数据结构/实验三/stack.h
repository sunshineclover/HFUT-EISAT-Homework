//ѧ�ţ�2020217793 ��������t�� �༶�����ſ�20-1��
#include <iostream>
using namespace std;

#define MaxLen 100
typedef char elementType;
typedef struct
{
    elementType data[MaxLen];
    int top;
} seqStack; //����˳��ջ

void initStack(seqStack &S) //��ʼ��ջ��ֻ��Ҫջ��ͷָ����-1���������ǽ�˳��ջ��ʼ����
{
    S.top = -1;
}

void pushStack(seqStack &S, elementType x) //��ջ
{
    if (S.top == MaxLen - 1)
    {
        cout << "˳��ջ����" << endl;
    }
    else
    {
        S.data[S.top + 1] = x; //�ȷ�Ԫ�أ����ƶ�ָ��
        S.top++;
    }
}

elementType popStack(seqStack &S) //��ջ
{
    if (S.top == -1)
    {
        cout << "ջ�ѿ�" << endl;
    }
    else
    {
        return S.data[S.top--]; //���س�ջ��Ԫ�� ͬʱ�ƶ�ͷָ��
    }
}
