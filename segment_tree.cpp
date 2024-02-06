#include<bits/stdc++.h>
using namespace std;


// MIN / MAX segment tree
class segment_tree
{
public:
    vector<int> a;
    segment_tree(int n)
    {
        a.resize(4 * n);
        cout<<"created\n";
    }

    void build(vector<int> num,int s,int e,int idx)     // O(4 * N) 
    {
        if(s == e) 
        {
            a[idx] = num[s];
            return;
        }

        int mid = s + (e - s) / 2;
        build(num,s,mid,(2 * idx) + 1);
        build(num,mid + 1,e,(2 * idx) + 2);

        a[idx] = min(a[(2 * idx) + 1],a[(2 * idx) + 2]);
    }

    void print()
    {
        for(auto i : a)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    int min_in_range(int s,int e,int l,int r,int idx)   // O(logN)
    {
        // no overlap
        if(l > e || r < s)
        {
            return INT_MAX;
        }

        // complete overlap
        if(l <= s && e <= r)
        {
            return a[idx];
        }

        // partial overlap
        int mid = s + (e - s) / 2;
        int left = min_in_range(s,mid,l,r,(2 * idx) + 1);
        int right = min_in_range(mid + 1,e,l,r,(2 * idx) + 2);

        return min(left,right);
    }

    void point_update(int i,int val,int s,int e,int idx)    // O(logN)
    {
        if(s == e)
        {
            a[idx] = val;
            return;
        }

        int mid = s + (e - s) / 2;
        if(mid >= i)
        {
            point_update(i,val,s,mid,(2 * idx) + 1);
        }
        else
        {
            point_update(i,val,mid + 1,e,(2 * idx) + 2);
        }

        a[idx] = min(a[(2 * idx) + 1],a[(2 * idx) + 2]);
    }
};


int main()
{
    vector<int> a = {1,5,2,4,6,7,2};
    int n = a.size();
    segment_tree s(n);
    s.build(a,0,n - 1,0);
    s.print();

    cout<<s.min_in_range(0,n - 1,3,5,0)<<endl;
    cout<<s.min_in_range(0,n - 1,0,n - 1,0)<<endl;
    cout<<s.min_in_range(0,n - 1,2,6,0)<<endl;
    s.point_update(1,0,0,n - 1,0);
    cout<<s.min_in_range(0,n - 1,3,5,0)<<endl;
    cout<<s.min_in_range(0,n - 1,0,n - 1,0)<<endl;
    cout<<s.min_in_range(0,n - 1,2,6,0)<<endl;
    
}