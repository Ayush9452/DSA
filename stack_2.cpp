#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void print_list(node *a)
{
    while (a != NULL)
    {
        cout << "ELEMENT = " << a->data << "\n";
        a = a->next;
    }
    // cout << "\n";
}

int isEmpty(node *a)
{
    if (a == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(node *a)
{
    node *n;
    n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}

node *push(node *a, int b)
{
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        cout << "STACK OVERFLOW!";
    }
    else
    {
        n->data = b;
        n->next = a;
        return n;
    }
}

int pop(node **a)
{
    if (isEmpty(*a))
    {
        cout << "STACK UNDERFLOW!\n";
        return -1;
    }
    node *x = *a;
    *a = (*a)->next;
    int val = x->data;
    free(x);
    return val;
}

int stack_top(node *a)
{
    return a->data;
}

int peek(node *a, int pos)
{
    for (int i = 1; i < pos && a != NULL; i++)
    {
        a = a->next;
    }
    if (a == NULL)
    {
        return -1;
    }
    return a->data;
}

int stack_bottom(node *a)
{
    node *n = (node *)malloc(sizeof(node));
    n = a;
    while (n->next != NULL)
    {
        n = n->next;
    }
    return n->data;
}

int main()
{
    node *a;
    a = (node *)malloc(sizeof(node));
    a = NULL;
    a = push(a, 199);
    a = push(a, 1434);
    a = push(a, 154545);
    a = push(a, 1465464);
    print_list(a);
    // cout << stack_top(a) << endl;
    // cout << peek(a, 10);
    // cout << stack_bottom(a) << endl;
    // cout << "POPED ELEMENT IS : " << pop(&a) << endl;
    // cout << "POPED ELEMENT IS : " << pop(&a) << endl;
    // cout << "POPED ELEMENT IS : " << pop(&a) << endl;
    // cout << "POPED ELEMENT IS : " << pop(&a) << endl;
    // cout << "POPED ELEMENT IS : " << pop(&a) << endl;
    return 0;
}