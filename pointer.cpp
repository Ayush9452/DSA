#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

void printarray(ll a[], ll n)
{
    fr(i, n)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // fast input output
    cout << endl;
    int i = 10;
    int *p;
    p = &i;
    cout << "The value of i is " << i << endl;
    cout << "The address of i is " << &i << endl;
    cout << "The value of i using pointer is " << *p << endl;
    cout << "The address of i using pointer is " << p << endl;
    cout << "The size of int pointer is " << sizeof(p) << endl;
    cout << endl;
    return 0;
}