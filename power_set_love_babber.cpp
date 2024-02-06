#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }
    //exclude
    solve(nums, output, index + 1, ans);
    //include
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
}

vector<vector<int>> sub_sequence(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // fast input output
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    // nums.push_back(3);
    vector<vector<int>> ans = sub_sequence(nums);
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