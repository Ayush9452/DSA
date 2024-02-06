#include <iostream>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

template <class T>
class vector
{
public:
    T *a;
    int size;
    vector(int m)
    {
        size = m;
        a = new T[size];
    }
    void output()
    {
        fr(i, size)
        {
            cout << a[i] << "  ";
        }
        cout << endl;
    }

    T dotproduct(vector &v)
    {
        T d = 0;
        fr(i, size)
        {
            d += (this->a[i]) * v.a[i];
        }
        return d;
    }
};

int main()
{
    vector<double> v1(3);
    v1.a[0] = 3.8;
    v1.a[1] = 7.4;
    v1.a[2] = 5.4;
    cout << "vector 1 = ";
    v1.output();
    vector<double> v2(3);
    v2.a[0] = 1.26875857;
    v2.a[1] = 2.3;
    v2.a[2] = 3.5;
    cout << "vector 2 = ";
    v2.output();
    cout << "Dotproduct of v1 and v2 is ";
    cout << v1.dotproduct(v2);
    return 0;
}