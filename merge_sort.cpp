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

void merge_of_two_array(int a[], int b[], int c[], int m, int n)
{
    int i, j, k;
    i = j = k = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < n)
    {
        c[k] = b[j];
        j++;
        k++;
    }
}

void merge_in_a_single_array(int a[], int low, int mid, int high)
{
    int c[high + 1];
    int i, j, k;
    k = low;
    i = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        j++;
        k++;
    }
    for (int x = low; x <= high; x++)
    {
        a[x] = c[x];
    }
}

void merge_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge_in_a_single_array(a, low, mid, high);
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
    merge_sort(a, 0, size - 1);
    printarray(a, size);
    return 0;
}