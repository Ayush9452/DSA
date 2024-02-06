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

void linear_ayush(int a[], int n, int b)
{
    int f = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b)
        {
            f = 0;
            cout << "THE ELEMENT " << b << "WAS FOUND AT INDEX : " << i << endl;
            return;
        }
    }
    if (f)
    {
        cout << "NOT FOUND\n";
        return;
    }
}

void binary_ayush(int a[], int n, int low, int high)
{
    int mid = (low + high) / 2;
    if (a[mid] == n)
    {
        cout << "THE ELEMENT " << n << "WAS FOUND AT INDEX : " << mid << endl;
        return;
    }
    else if (low > high)
    {
        cout << "NOT FOUND\n";
        return;
    }
    else if (a[mid] > n)
    {
        return binary_ayush(a, n, low, mid - 1);
    }
    else
    {
        return binary_ayush(a, n, mid + 1, high);
    }
}

int main()
{
    int n;
    cout << "ENTER THE SIZE OF THE ARRAY : ";
    cin >> n;
    int a[n];
    fr(i, n)
    {
        cout << "ENTER THE ELEMENT OF THE ARRAY : ";
        cin >> a[i];
    }
    cout << "ARRAY IS AS FOLLOWING : ";
    printarray(a, n);
    int x;
    cout << "ENTER THE NUMBER TO BE ayushED : ";
    cin >> x;
    cout << "\nLINEAR ayush\n";
    linear_ayush(a, n, x);
    cout << "\nBINARY ayush\n";
    binary_ayush(a, x, 0, n - 1);
    return 0;
}