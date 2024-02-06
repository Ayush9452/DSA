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
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    vector<string> st(n);
    fr(i, n)
    {
        string s1;
        getline(cin, s1);
        st[i] = s1;
    }
    int q;
    cin >> q;
    vector<string> st2(q);
    getline(cin, s);
    fr(i, q)
    {
        string s2;
        getline(cin, s2);
        st2[i] = s2;
    }
    fr(i, q)
    {
        int t = 0;
        fr(j, n)
        {
            if (st2[i] == st[j])
            {
                t++;
            }
        }
        cout << t << endl;
    }
    // fr(i, q)
    // {
    //     cout << st2[i] << endl;
    // }
    // fr(i, n)
    // {
    //     cout << st[i] << endl;
    // }
    return 0;
}