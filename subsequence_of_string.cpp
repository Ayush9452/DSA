#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

void solve(string nums, string output, int index, vector<string> &ans)
{
    if (index >= nums.length())
    {
        ans.push_back(output);
        return;
    }
    solve(nums, output, index + 1, ans);
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
}

vector<string> sub_sequence(string nums)
{
    vector<string> ans;
    string output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // fast input output
    string nums;
    nums = "abc";
    // nums.push_back(3);
    vector<string> ans = sub_sequence(nums);
    sort(ans.begin(), ans.end());
    fr(i, ans.size())
    {
        cout << ans[i];
        NL;
    }
    return 0;
}