#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

void printarray(ll a[], ll n)
{
    fr(i, n)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void setarray(ll a[], ll n)
{
    fr(i, n)
    {
        cin >> a[i];
    }
}

bool if_poss(vector<vector<int>> &v, int n, int x, int y, vector<vector<bool>> &visited)
{
    if ((x >= 0 && x <= n - 1) && (y >= 0 && y <= n - 1) && v[x][y] == 1 && visited[x][y] == 0)
    {
        return 1;
    }
    return 0;
}

void solve(vector<vector<int>> &v, int n, int x, int y, vector<string> &ans, string path, vector<vector<bool>> &visited)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // down
    int new_x = x + 1;
    int new_y = y;
    if (if_poss(v, n, new_x, new_y, visited))
    {
        path.push_back('D');
        solve(v, n, new_x, new_y, ans, path, visited);
        path.pop_back();
    }

    // left
    new_x = x;
    new_y = y - 1;
    if (if_poss(v, n, new_x, new_y, visited))
    {
        path.push_back('L');
        solve(v, n, new_x, new_y, ans, path, visited);
        path.pop_back();
    }

    // right
    new_x = x;
    new_y = y + 1;
    if (if_poss(v, n, new_x, new_y, visited))
    {
        path.push_back('R');
        solve(v, n, new_x, new_y, ans, path, visited);
        path.pop_back();
    }

    // up
    new_x = x - 1;
    new_y = y;
    if (if_poss(v, n, new_x, new_y, visited))
    {
        path.push_back('U');
        solve(v, n, new_x, new_y, ans, path, visited);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> rat_in_a_maze(vector<vector<int>> &v, int n) // T(4^(n*n))  S(n*n)
{
    vector<string> ans;
    if (v[0][0] == 0)
    {
        return ans;
    }

    int startx = 0;
    int starty = 0;

    string path = "";
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    solve(v, n, startx, starty, ans, path, visited);
    sort(ans.begin(), ans.end());
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

    fr(i, n)
    {
        fr(j, n)
        {
            cout << m[i][j] << " ";
        }
        NL;
    }

    vector<string> s;
    s = rat_in_a_maze(m, n);

    fr(i, s.size())
    {
        cout << s[i] << endl;
    }
    return 0;
}