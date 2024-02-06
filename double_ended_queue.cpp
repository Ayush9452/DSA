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

void enqueue_back(queu *a, int b)
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

void enqueue_front(queu *a, int b)
{
    if (isFull(a) || a->front_index == -1)
    {
        cout << "CANNOT ENQUEUE! FRONT IS ALREADY OCCUPIED\n";
        return;
    }
    a->data[a->front_index] = b;
    a->front_index--;
}

int dequeue_front(queu *a)
{
    if (!isEmpty(a))
    {
        a->front_index++;
        int val = a->data[a->front_index];
        return val;
    }
    cout << "QUEUE UNDERFLOW! ERROR CODE 101\n";
    return -1;
}

int dequeue_back(queu *a)
{
    if (!isEmpty(a))
    {
        int val = a->data[a->back_index];
        a->back_index--;
        return val;
    }
    cout << "QUEUE UNDERFLOW! ERROR CODE 102\n";
    return -1;
}

void print_queue(queu a)
{
    cout << "QUEUE ELEMENT : ";
    for (int i = a.front_index + 1; i <= a.back_index; i++)
    {
        cout << a.data[i] << " ";
    }
    cout << endl;
}

int main()
{
    queu q;
    q.size = 100;
    q.back_index = q.front_index = -1;
    q.data = (int *)malloc(q.size * sizeof(int));
    enqueue_back(&q, 1);
    enqueue_back(&q, 2);
    enqueue_back(&q, 3);
    enqueue_back(&q, 4);
    print_queue(q);
    enqueue_front(&q, 5);
    print_queue(q);
    dequeue_front(&q);
    enqueue_front(&q, 5);
    dequeue_back(&q);
    print_queue(q);
    return 0;
}