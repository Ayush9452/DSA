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

char pop(stackk *a)
{
    char x;
    x = a->arr[a->top];
    a->top--;
    return x;
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '<' && b == '>')
    {
        return 1;
    }
    return 0;
}

void Parenthesis_multi_macthing(string s)
{
    int l = s.length();
    stackk *a;
    a = (stackk *)malloc(sizeof(stackk));
    a->size = l;
    a->top = -1;
    a->arr = (char *)malloc(a->size * sizeof(char));
    char popped;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<')
        {
            push(a, s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']' || s[i] == '>')
        {
            if (isEmpty(a))
            {
                cout << "UNBLANCE\n";
                return;
            }
            popped = pop(a);
            if (!match(popped, s[i]))
            {
                cout << "UNBLANCE\n";
                return;
            }
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
    // s = "[4-6]((8){(9-8)})";
    Parenthesis_multi_macthing(s);
    return 0;
}