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
    if ((a->back_index + 1) % a->size == a->front_index)
    {
        return 1;
    }
    return 0;
}

void enqueue(queu *a, int b)
{
    if (!isFull(a))
    {
        a->back_index = (a->back_index + 1) % a->size;
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
        a->front_index = (a->front_index + 1) % a->size;
        int val = a->data[a->front_index];
        return val;
    }
    else
    {
        cout << "QUEUE UNDERFLOW! ERROR CODE 101\n";
        return -1;
    }
}

int peek_front(queu a)
{
    return a.data[a.front_index];
}

int peek_back(queu a)
{
    return a.data[a.back_index];
}

int main()
{
    queu q;
    q.size = 4;
    q.back_index = q.front_index = 0;
    q.data = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 21);
    enqueue(&q, 42);
    enqueue(&q, 63);
    cout << dequeue(&q) << endl;
    cout << dequeue(&q) << endl;
    cout << dequeue(&q) << endl;
    cout << dequeue(&q) << endl;
    cout << isFull(&q) << endl;
    cout << isEmpty(&q) << endl;
    return 0;
}