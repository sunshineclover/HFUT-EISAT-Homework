//ѧ�ţ�2020217793 ��������t�� �༶�����ſ�20-1��
#include "linkstack.h"
int main()
{
    int x;
    elementType t;
    linkStack S;
    S = createStack();
    cout << "1.��10������ת��Ϊ16������" << endl;
    cout << "2.�жϸ������Ƿ��໥ƥ��" << endl;
    cout << "����������ִ�е����" << endl;
    cin >> x;
    switch (x)
    {
    case 1:
    {
        int n;
        cout << "������һ��10������" << endl;
        cin >> n;
        while (n > 0)
        {
            if (n % 16 < 10) //�ж��������0-9����abcdef��ʹ�ò�ͬ������¶�����ȷ��ջ
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
        while (S->next) //���ջ������Ԫ��
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
        cout << "������һ�����ʽ" << endl;
        cin >> equation;
        for (int i = 0; equation[i]; i++)
        {
            if (equation[i] == '{' || equation[i] == '[' || equation[i] == '(')
                pushStack(S, equation[i]);
            if (equation[i] == ')') //����һ�����ų���ʱ���ж��Ƿ�ƥ��
            {
                t = popStack(S);
                if (t != '(')
                {
                    cout << "�ñ��ʽ���Ų�ƥ��" << endl;
                    break;
                }
            }
            else if (equation[i] == ']') //����һ�����ų���ʱ���ж��Ƿ�ƥ��
            {
                t = popStack(S);
                if (t != '[')
                {
                    cout << "�ñ��ʽ���Ų�ƥ��" << endl;
                    break;
                }
            }
            else if (equation[i] == '}') //����һ�����ų���ʱ���ж��Ƿ�ƥ��
            {
                t = popStack(S);
                if (t != '{')
                {
                    cout << "�ñ��ʽ���Ų�ƥ��" << endl;
                    break;
                }
            }
        }
        if (S->next == NULL)
        {
            cout << "�ñ��ʽ����ƥ��" << endl;
        }
        else
        {
            cout << "�ñ��ʽ���Ų�ƥ��" << endl;
        }
        break;
    }
    }
    return 0;
}