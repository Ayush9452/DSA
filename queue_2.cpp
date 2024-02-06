#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

node *f = NULL;
node *b = NULL;

int isFull()
{
    node *n;
    n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty(node *a)
{
    if (a == NULL)
    {
        return 1;
    }
    return 0;
}

void print_list(node *a)
{
    cout << "-----PRINTING LIST DATA-----\n";
    if (isEmpty(f))
    {
        cout << "NOTHING TO PRINT\n";
        return;
    }
    while (a != NULL)
    {
        cout << "ELEMENT : " << a->data << endl;
        a = a->next;
    }
}

void enqueue(int val)
{
    node *n;
    n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        cout << "QUEUE OVERFLOW! ERROR CODE : -1\n";
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = b = n;
        }
        else
        {
            b->next = n;
            b = n;
        }
    }
}

int dequeue()
{
    if (isEmpty(f))
    {
        cout << "QUEUE UNDERFLOW! error code 101\n";
        return -1;
    }
    node *a = f;
    f = f->next;
    int val = a->data;
    free(a);
    return val;
}

int main()
{
    enqueue(34);
    enqueue(3);
    enqueue(65);
    print_list(f);
    cout << "DEQUEUED ELEMENT : " << dequeue() << endl;
    cout << "DEQUEUED ELEMENT : " << dequeue() << endl;
    cout << "DEQUEUED ELEMENT : " << dequeue() << endl;
    cout << "DEQUEUED ELEMENT : " << dequeue() << endl;
    print_list(f);
    return 0;
}