#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

// Segmented sieve
int count_prime(int n)
{
    vector<int> prime;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 2, true);
    for (int j = 2; j <= nsqrt; j++)
    {
        if (is_prime[j])
        {
            prime.push_back(j);
            for (int i = j * j; i <= nsqrt; i += j)
            {
                is_prime[j] = false;
            }
        }
    }

    int result = 0;

    int S = 10000;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++)
    {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (auto p : prime)
        {
            int start_index = (start + p - 1) / p;
            int j = max(start_index, p) * p - start;
            for (; j < S; j += p)
            {
                block[j] = false;
            }
        }

        if (k == 0)
        {
            block[0] = block[1] = false;
        }
        for (int j = 0; j < S && start + j <= n; j++)
        {
            if (block[j])
            {
                result++;
            }
        }
    }

    return result;
}

// prime in a range
int prime_L_R(ll L,ll R)
{
    vector<char> prime(R - L + 1,true);
    ll lim = sqrt(R);
    for(ll i = 2;i <= lim;i++)
    {
        for(ll j = max(i * i,(L + i - 1)/ i * i);j <= R;j += i)
        {
            prime[j - L] = false;
        }
    }

    if(L == 1)
    {
        prime[0] = false;
    }

    ll result = 0;

    for(ll i = 0;i < (R - L + 1);i++)
    {
        if(prime[i])
        {   
            result++;
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // fast input output
    int t;
    cin>>t;
    while(t--)
    {
    }
    return 0;
}