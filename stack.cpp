#include <bits/stdc++.h>
using namespace std;

class stackk
{
public:
    int size, top;
    int *arr;
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

int isFull(stackk *a)
{
    if (a->top == ((a->size) - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(stackk *a, int b)
{
    if (isFull(a))
    {
        printf("STACK OVERFLOW!\n");
        return;
    }
    a->top++;
    a->arr[a->top] = b;
}

int pop(stackk *a)
{
    if (isEmpty(a))
    {
        printf("STACK UNDERFLOW!\n");
        return -1;
    }
    int val = a->arr[a->top];
    a->top--;
    return val;
}

int peek(stackk *a, int pos)
{
    if (isEmpty(a))
    {
        cout << "STACK UNDERFLOW! CANNOT PEEK\n";
        return -1;
    }
    else
    {
        if (pos > a->top + 1)
        {
            cout << "INVALID INPUT! POSITION NOT FOUND\n";
            return -1;
        }
        return a->arr[a->top - pos + 1];
    }
}

int stack_top(stackk *a)
{
    if (isEmpty(a))
    {
        cout << "STACK UNDERFLOW!\n";
        return -1;
    }
    else
    {
        return a->arr[a->top];
    }
}

int stack_bottom(stackk *a)
{
    if (isEmpty(a))
    {
        cout << "STACK UNDERFLOW!\n";
        return -1;
    }
    else
    {
        return a->arr[0];
    }
}

int main()
{
    // cout<<"hello world";
    stackk *a;
    a = (stackk *)malloc(sizeof(stackk));
    a->size = 100;
    a->top = -1;
    a->arr = (int *)malloc(a->size * sizeof(int));
    push(a, 1);
    push(a, 2);
    push(a, 3);
    push(a, 4);
    push(a, 5);
    push(a, 6);
    push(a, 7);
    cout << peek(a, 1) << endl;
    cout << pop(a) << endl;
    cout << pop(a) << endl;
    cout << pop(a) << endl;
    cout << pop(a) << endl;
    cout << pop(a) << endl;
    cout << pop(a) << endl;
    cout << pop(a) << endl;
    cout << pop(a) << endl;
    return 0;
}