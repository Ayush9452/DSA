#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

class stackk
{
public:
    int size;
    int top;
    char *arr;
};

int isEmpty(stackk *a)
{
    if (a->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(stackk *a, char c)
{
    a->top++;
    a->arr[a->top] = c;
}

char pop(stackk *a)
{
    char c = a->arr[a->top];
    a->top--;
    return c;
}

char stack_top(stackk *a)
{
    return a->arr[a->top];
}

int ifOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
    {
        return 1;
    }
    return 0;
}

int prec(char c)
{
    if (c == '+' || c == '-')
    {
        return 2;
    }
    else if (c == '*' || c == '/')
    {
        return 3;
    }
    else if (c == '^')
    {
        return 4;
    }
    return -1;
}

void infix_to_postfix(string s)
{
    string ans = "";
    stackk *a = (stackk *)malloc(sizeof(stackk));
    a->size = s.length();
    a->top = -1;
    a->arr = (char *)malloc(a->size * sizeof(char));
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            push(a, s[i]);
        }
        else if (s[i] == ')')
        {
            while (stack_top(a) != '(')
            {
                ans += stack_top(a);
                pop(a);
            }
            pop(a);
        }
        else
        {
            while (!isEmpty(a) && prec(s[i]) <= prec(stack_top(a)))
            {
                if (s[i] == '^' && stack_top(a) != '^')
                    break;
                else
                {
                    ans += stack_top(a);
                    pop(a);
                }
            }
            push(a, s[i]);
        }
    }

    while (!isEmpty(a))
    {
        ans += stack_top(a);
        pop(a);
    }
    cout << ans << endl;
}

int main()
{
    string s = "a+b*(c^d-e)^(f+g*h)-i";
    infix_to_postfix(s);
    return 0;
}