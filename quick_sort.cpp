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

int partion_index(int a[], int low, int high)
{
    int i = low + 1;
    int j = high;
    do
    {
        while (a[i] <= a[low])
        {
            i++;
        }
        while (a[j] >= a[low])
        {
            j--;
        }
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    } while (i < j);
    swap(a[low], a[j]);
    return j;
}

void quick_sort(int a[], int x, int y)
{

    if (x < y)
    {
        int p;
        p = partion_index(a, x, y); 
        quick_sort(a, x, p - 1);
        quick_sort(a, p + 1, y);
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
    quick_sort(a, 0, size - 1);
    printarray(a, size);
    return 0;
}