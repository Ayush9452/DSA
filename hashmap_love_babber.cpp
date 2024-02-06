#include<bits/stdc++.h>
#define ll long long
#define NL cout<<endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;


int main()
{
    unordered_map<string,int> m;

    // m.count(key) ------>  if present = 1 else 0
    // m.erase(key) ------>  deletion
    // m[key]       ------> always create a new pair if the key does not exist in map e.g., cout << m["mera"] << endl;  creates {"mera",0}
    
    // ------------------- Traversal ----------------------

    unordered_map<string,int> :: iterator it = m.begin();
   
    return 0;
}