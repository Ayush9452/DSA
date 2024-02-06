#include <bits/stdc++.h>
using namespace std;

int a[7][7] =
    {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
};

void DFS(int i)
{
    int j;
    static int visited[7] = {0};
    visited[i] = 1;
    cout << i << " ";
    for (j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    DFS(0);
    return 0;
}