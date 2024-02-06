#include <bits/stdc++.h>
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
    else
    {
        return 0;
    }
}

void push(stackk *a, char c)
{
    a->top++;
    a->arr[a->top] = c;
}

int pop(stackk *a)
{
    a->top--;
    return 1;
}


void Parenthesis_macthing(string s)
{
    int l = s.length();
    stackk *a;
    a = (stackk *)malloc(sizeof(stackk));
    a->size = l;
    a->top = -1;
    a->arr = (char *)malloc(a->size * sizeof(char));
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '(')
        {
            push(a, s[i]);
        }
        else if (s[i] == ')')
        {
            if (isEmpty(a))
            {
                cout << "UNBLANCE\n";
                return;
            }
            pop(a);
        }
    }
    if (isEmpty(a))
    {
        cout << "BALANCED\n";
    }
    else
    {
        cout << "UNBLANCE\n";
    }
    return;
}

int main()
{
    string s;
    cin >> s;
    // cout << s.length() << endl;
    Parenthesis_macthing(s);
    return 0;
}