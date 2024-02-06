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

void selection_sort(int *a, int n)
{
    int i = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // cout << i << endl;
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min_idx] > a[j])
            {
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
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
    printarray(a, size);
    selection_sort(a, size);
    printarray(a, size);
    return 0;
}