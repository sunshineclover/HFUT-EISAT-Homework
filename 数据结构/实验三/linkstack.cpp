//学号：2020217793 姓名：洪祎麟 班级：电信科20-1班
#include "linkstack.h"
int main()
{
    int x;
    elementType t;
    linkStack S;
    S = createStack();
    cout << "1.将10进制数转化为16进制数" << endl;
    cout << "2.判断各符号是否相互匹配" << endl;
    cout << "请输入你想执行的序号" << endl;
    cin >> x;
    switch (x)
    {
    case 1:
    {
        int n;
        cout << "请输入一个10进制数" << endl;
        cin >> n;
        while (n > 0)
        {
            if (n % 16 < 10) //判断这个数是0-9还是abcdef，使得不同种情况下都能正确入栈
            {
                pushStack(S, char(n % 16 + 48));
            }
            else if (n % 16 == 10)
                pushStack(S, 'A');
            else if (n % 16 == 11)
                pushStack(S, 'B');
            else if (n % 16 == 12)
                pushStack(S, 'C');
            else if (n % 16 == 13)
                pushStack(S, 'D');
            else if (n % 16 == 14)
                pushStack(S, 'E');
            else if (n % 16 == 15)
                pushStack(S, 'F');
            n = n / 16;
        }
        while (S->next) //输出栈内所有元素
        {
            t = popStack(S);
            cout << t;
        }

        break;
    }
    case 2:
    {
        char equation[80];
        int t;
        cout << "请输入一个表达式" << endl;
        cin >> equation;
        for (int i = 0; equation[i]; i++)
        {
            if (equation[i] == '{' || equation[i] == '[' || equation[i] == '(')
                pushStack(S, equation[i]);
            if (equation[i] == ')') //当另一个括号出现时，判断是否匹配
            {
                t = popStack(S);
                if (t != '(')
                {
                    cout << "该表达式括号不匹配" << endl;
                    break;
                }
            }
            else if (equation[i] == ']') //当另一个括号出现时，判断是否匹配
            {
                t = popStack(S);
                if (t != '[')
                {
                    cout << "该表达式括号不匹配" << endl;
                    break;
                }
            }
            else if (equation[i] == '}') //当另一个括号出现时，判断是否匹配
            {
                t = popStack(S);
                if (t != '{')
                {
                    cout << "该表达式括号不匹配" << endl;
                    break;
                }
            }
        }
        if (S->next == NULL)
        {
            cout << "该表达式括号匹配" << endl;
        }
        else
        {
            cout << "该表达式括号不匹配" << endl;
        }
        break;
    }
    }
    return 0;
}