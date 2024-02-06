#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;
class Student
{
    int age;
    string first_name;
    string last_name;
    int standard;

    string to_string()
    {
        stringstream s;
        char a{','};
        s << age << a << first_name << a << last_name << a << standard;
        return s.str();
    }
};

int main()
{

    return 0;
}