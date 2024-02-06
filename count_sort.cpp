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

void count_sort(int a[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    int b[max + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
    }
    int k = 0;
    for (int i = 0; i < max + 1; i++)
    {
        while (b[i] != 0)
        {
            a[k] = i;
            k++;
            b[i]--;
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
    count_sort(a,size);
    printarray(a, size);
    return 0;
}