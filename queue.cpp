#include <bits/stdc++.h>
using namespace std;

class queu
{
public:
    int size;
    int *data;
    int front_index;
    int back_index;
};

int isEmpty(queu *a)
{
    if (a->back_index == a->front_index)
    {
        return 1;
    }
    return 0;
}

int isFull(queu *a)
{
    if (a->back_index == a->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(queu *a, int b)
{
    if (!isFull(a))
    {
        a->back_index++;
        a->data[a->back_index] = b;
    }
    else
    {
        cout << "QUEUE OVERFLOW! ERROR CODE : 101\n";
    }
}

int dequeue(queu *a)
{
    if (!isEmpty(a))
    {
        a->front_index++;
        int val = a->data[a->front_index];
        return val;
    }
    else
    {
        cout << "QUEUE UNDERFLOW! ERROR CODE : \n";
        return -1;
    }
}

int peek(queu a, int pos)
{
    if (pos - 1 > a.back_index)
    {
        cout << "INVALID INPUT! POSITION NOT FOUND, ERROR CODE :";
        return -1;
    }
    return a.data[pos - 1];
}

int main()
{
    queu q;
    q.size = 100;
    q.back_index = q.front_index = -1;
    q.data = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 21);
    enqueue(&q, 42);
    enqueue(&q, 63);
    enqueue(&q, 84);
    cout << peek(q, 1) << endl;
    cout << peek(q, 2) << endl;
    cout << peek(q, 3) << endl;
    cout << peek(q, 4) << endl;
    cout << peek(q, 5) << endl;
    return 0;
}