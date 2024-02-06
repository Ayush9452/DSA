#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

class myarray
{
    int tsize;
    int usize;
    int *ptr;

public:
    myarray(int a, int b)
    {
        tsize = a;
        usize = b;
        ptr = (int *)malloc(tsize * sizeof(int));
    }

    void display()
    {
        for (int i = 0; i < usize; i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }
    void set()
    {
        for (int i = 0; i < usize; i++)
        {
            cout << "Enter the number at position " << i + 1 << " : ";
            cin >> ptr[i];
        }
    }
    void insert_last(int a)
    {
        if (usize >= tsize)
        {
            cout << "INSERTION UNSUCCESSFUL\n";
            return;
        }
        else
        {
            ptr[usize] = a;
            usize++;
        }
    }

    void insert(int a, int pos)
    {
        if (usize >= tsize)
        {
            cout << "INSERTION UNSUCCESSFUL\n";
            return;
        }
        else
        {
            ptr[usize] = ptr[pos - 1];
            usize++;
            ptr[pos - 1] = a;
        }
    }

    void ordered_insert(int a, int pos)
    {
        if (usize >= tsize)
        {
            cout << "INSERTION UNSUCCESSFUL\n";
            return;
        }
        else
        {
            for (int i = usize; i > pos - 1; i--)
            {
                ptr[i] = ptr[i - 1];
            }
            ptr[pos - 1] = a;
            usize++;
        }
    }

    void ordered_remove(int a)
    {

        for (int i = a - 1; i < usize - 1; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        usize--;
    }

    void remove_fast(int a)
    {
        ptr[a - 1] = ptr[usize - 1];
        usize--;
    }
};

int main()
{
    int n, m;
    cout << "Enter the total size of the array : ";
    cin >> n;
    cout << "Enter the used size of the array : ";
    cin >> m;
    int a, b, pos;
    myarray harry(n, m);
    harry.set();
    harry.display();
    cout << "Enter the number you want to insert : ";
    cin >> a;
    harry.insert_last(a);
    harry.display();
    cout << "Enter the number you want to insert : ";
    cin >> b;
    cout << "Enter the position you want to insert : ";
    cin >> pos;
    harry.ordered_insert(b, pos);
    harry.display();
    return 0;
}