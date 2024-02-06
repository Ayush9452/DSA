#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

class queu
{
public:
    int size;
    int f, r;
    int *arr;
};

int isEmpty(queu *a)
{
    if (a->f == a->r)
    {
        return 1;
    }
    return 0;
}

int isFull(queu *a)
{
    if (a->r == a->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueu(queu *a, int val)
{
    if (isFull(a))
    {
        cout << "QUEUE IS FULL\n";
        return;
    }
    a->r++;
    a->arr[a->r] = val;
    return;
}

int dequeu(queu *a)
{
    if (isEmpty(a))
    {
        cout << "QUEUE IS EMPTY\n";
        return -1;
    }
    a->f++;
    return a->arr[a->f];
}

int main()
{
    queu q;
    q.f = q.r = -1;
    q.size = 100;
    q.arr = (int *)malloc(q.size * sizeof(int));
    // BFS IMPLIMENTAION
    int node;
    int i = 0;
    int visited[7] = {0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };
    cout << i << " ";
    visited[i] = 1;
    enqueu(&q, i);
    while (!isEmpty(&q))
    {
        int node = dequeu(&q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                enqueu(&q, j);
            }
        }
    }
    return 0;
}