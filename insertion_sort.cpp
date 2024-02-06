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

void insertion_sort(int *a, int n)
{
    int i = 1;
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (a[j] < a[j - 1] && j - 1 >= 0)
        {
            swap(a[j], a[j - 1]);
            j--;
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
    printarray(a, size);
    insertion_sort(a, size);
    printarray(a, size);
    return 0;
}