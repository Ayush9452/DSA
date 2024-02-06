#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

void printarray(int a[], int n)
{
    fr(i, n)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Adaptive bubble sort
void bubble_sort(int *a, int size)
{
    int issorted = 0;
    int sum = 0;
    for (int i = 0; i < size - 1; i++)
    {
        issorted = 1;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                cout << a[j] << " ";
                cout << a[j + 1] << endl;
                swap(a[j + 1], a[j]);
                sum++;
                issorted = 0;
            }
        }
        cout << endl;
        if (issorted)
        {
            return;
        }
    }
}

int main()
{
    int size;
    cin >> size;
    int a[size];
    fr(i, size)
    {
        cin >> a[i];
    }
    // printarray(a, size);
    bubble_sort(a, size);
    // printarray(a, size);
    return 0;
}