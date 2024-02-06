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
    node *next;
};

void print_list(node *a)
{
    node *head = a;
    do
    {
        cout << a->data << " ";
        a = a->next;
    } while (a != head);
    cout << "\n";
}

node *insert_in_the_start(node *a, int b)
{
    node *x = (node *)malloc(sizeof(node));
    x->data = b;
    x->next = a;
    node *p = a->next;
    while (p->next != a)
    {
        p = p->next;
    }
    p->next = x;
    return x;
}

int main()
{

    // Allocated in heap
    node *head = (node *)malloc(sizeof(node));
    node *second = (node *)malloc(sizeof(node));
    node *third = (node *)malloc(sizeof(node));
    node *fourth = (node *)malloc(sizeof(node));

    head->data = 7;
    head->next = second; // linking first and second nodes

    second->data = 14;
    second->next = third;

    third->data = 21;
    third->next = fourth;

    fourth->data = 87;
    fourth->next = head;

    cout << "LINKED LIST : ";
    print_list(head);
    head = insert_in_the_start(head, 69);
    print_list(head);
    return 0;
}