#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

void solve(string number, string output, int index, vector<string> &ans, string mapping[])
{
    if (index >= number.length())
    {
        ans.push_back(output);
        return;
    }
    int digit = number[index] - '0';
    string alphabates = mapping[digit];
    for(int i=0;i<alphabates.length();i++){
        output.push_back(alphabates[i]);
        solve(number, output, index + 1, ans, mapping);
        //back_track
        output.pop_back();
    }
}

vector<string> keypad(string number)
{
    vector<string> ans;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output = "";
    int index = 0;
    solve(number, output, index, ans, mapping);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // fast input output
    string nums;
    nums = "232";
    // nums.push_back(3);
    vector<string> ans = keypad(nums);
    fr(i, ans.size())
    {
        cout << ans[i];
        NL;
    }

    return 0;
}