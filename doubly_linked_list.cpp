#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;
};

void print_list(node *head)
{
    node *p = head;
    node *c = p;
    cout << "LIST IN FORWARD ORDER : ";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
        if (p != NULL)
        {
            c = p;
        }
    }
    cout << "\n";
    cout << "LIST IN REVERSE ORDER : ";
    while (c != NULL)
    {
        cout << c->data << " ";
        c = c->prev;
    }
    cout << "\n";
}

node *insert_at_the_end(node *a, int val)
{
    node *p = a;
    while (p->next != NULL)
    {
        p = p->next;
    }
    node *x = (node *)malloc(sizeof(node));
    x->data = val;
    x->next = NULL;
    x->prev = p;
    p->next = x;
    return a;
}

node *reverse_list(node *a)
{
    node *p = a;
    node *tail;
    while (p->next != NULL)
    {
        p = p->next;
    }
    tail = p;
    p = a;
    while (p != NULL)
    {
        node *x = p->prev;
        node *y = p->next;
        p->next = x;
        p->prev = y;
        p = y;
    }
    return tail;
}

int main()
{
    node *head = (node *)malloc(sizeof(node));
    node *second = (node *)malloc(sizeof(node));
    node *third = (node *)malloc(sizeof(node));
    node *fourth = (node *)malloc(sizeof(node));

    head->prev = NULL;
    head->data = 1;
    head->next = second;

    second->prev = head;
    second->data = 2;
    second->next = third;

    third->prev = second;
    third->data = 3;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 4;
    fourth->next = NULL;

    print_list(head);
    return 0;
}