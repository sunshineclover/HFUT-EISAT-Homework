//学号：2020217793 姓名：洪祎麟 班级：电信科20-1班
#include <iostream>
using namespace std;

#define MaxLen 100
typedef char elementType;
typedef struct
{
    elementType data[MaxLen];
    int top;
} seqStack; //创建顺序栈

void initStack(seqStack &S) //初始化栈（只需要栈的头指针在-1处即看作是将顺序栈初始化）
{
    S.top = -1;
}

void pushStack(seqStack &S, elementType x) //入栈
{
    if (S.top == MaxLen - 1)
    {
        cout << "顺序栈已满" << endl;
    }
    else
    {
        S.data[S.top + 1] = x; //先放元素，在移动指针
        S.top++;
    }
}

elementType popStack(seqStack &S) //出栈
{
    if (S.top == -1)
    {
        cout << "栈已空" << endl;
    }
    else
    {
        return S.data[S.top--]; //带回出栈的元素 同时移动头指针
    }
}
