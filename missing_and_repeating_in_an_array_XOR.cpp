#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

// USING XOR
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // fast input output
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int temp = 0;
    for (int i = 1; i <= n; i++)
    {
        temp = temp ^ i;
        temp = temp ^ a[i - 1];
    }
    int bit = 0;
    while (!(temp & 1))
    {
        bit++;
        temp = temp >> 1;
    }

    int c1 = 0, c0 = 0;
    int mask = 1 << bit;
    for (int i = 0; i < n; i++)
    {
        if (a[i] & mask)
        {
            c1 = c1 ^ a[i];
        }
        else
        {
            c0 = c0 ^ a[i];
        }
        if ((i + 1) & mask)
        {
            c1 = c1 ^ (i + 1);
        }
        else
        {
            c0 = c0 ^ (i + 1);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == c0)
        {
            cnt++;
        }
    }
    
    if (cnt == 2)
    {
        cout << "MISSING = " << c1 << endl;
        cout << "REPEATING = " << c0 << endl;
    }
    else
    {
        cout << "MISSING = " << c0 << endl;
        cout << "REPEATING = " << c1 << endl;
    }
    return 0;
}