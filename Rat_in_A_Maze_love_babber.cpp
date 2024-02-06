#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

bool poss(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited)
{
    if ((x >= 0 && x <= n - 1) && (y >= 0 && y <= n - 1) && m[x][y] == 1 && visited[x][y] == 0)
    {
        return 1;
    }
    return 0;
}

void solve(vector<vector<int>> m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path)
{
    
    cout << x << " " << y << endl;
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // right
    int newx = x;
    int newy = y + 1;
    if (poss(m, n, newx, newy, visited))
    {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // left
    newx = x;
    newy = y - 1;
    if (poss(m, n, newx, newy, visited))
    {
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // UP
    newx = x - 1;
    newy = y;
    if (poss(m, n, newx, newy, visited))
    {
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    // down
    newx = x + 1;
    newy = y;
    if (poss(m, n, newx, newy, visited))
    {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    visited[x][y] = 0;
}

vector<string> final_path(vector<vector<int>> m, int n)
{
    vector<string> ans;
    int scrx = 0;
    int scry = 0;

    if (m[0][0] == 0)
    {
        return ans;
    }

    vector<vector<int>> visited = m;
    fr(i, n)
    {
        fr(j, n)
        {
            visited[i][j] = 0;
        }
    }
    
    string path = "";
    solve(m, n, ans, scrx, scry, visited, path);
    // sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // fast input output
    vector<vector<int>> m;
    int n;
    cin >> n;
    fr(i, n)
    {
        vector<int> v;
        fr(j, n)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        m.push_back(v);
    }

    // fr(i, n)
    // {
    //     fr(j, n)
    //     {
    //         cout << m[i][j] << " ";
    //     }
    //     NL;
    // }

    vector<string> s;
    s = final_path(m, n);

    fr(i, s.size())
    {
        cout << s[i] << endl;
    }
    return 0;
}