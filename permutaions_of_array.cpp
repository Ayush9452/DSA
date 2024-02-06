#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

void solve(vector<int> nums, vector<vector<int>> &ans, int index)
{
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, ans, index + 1);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permutaions(vector<int> nums)
{
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // fast input output
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    // a.push_back(4);
    vector<vector<int>> ans = permutaions(a);
    fr(i, ans.size())
    {
        fr(j, ans[i].size())
        {
            cout << ans[i][j] << " ";
        }
        NL;
    }
    return 0;
}