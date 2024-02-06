#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

bool if_poss(int row, int col, vector<vector<int>> &board, int n)
{
    // checking row
    int x = row;
    int y = col;
    while (y >= 0)
    {
        if (board[x][y])
        {
            return 0;
        }
        y--;
    }
    // checking diagonal
    // upper diagonal
    int temp_row = row;
    int temp_col = col;
    while (temp_row >= 0 && temp_col >= 0)
    {
        if (board[temp_row][temp_col])
        {
            return 0;
        }
        temp_row--;
        temp_col--;
    }
    // lower daigonal
    temp_row = row;
    temp_col = col;
    while (temp_row < n && temp_col >= 0)
    {
        if (board[temp_row][temp_col])
        {
            return 0;
        }
        temp_row++;
        temp_col--;
    }

    return 1;
}

void add(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n) // row \/  col ->
{
    if (col == n)
    {
        // add(board, ans, n); // tern whole 2D array into 1D then insert it
        ans = board;
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (if_poss(row, col, board, n))
        {
            board[row][col] = 1;
            solve(col + 1, board, ans, n);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> N_queen(int n) // T(n!)  S(n*n)
{
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));

    solve(0, board, ans, n);

    return ans;
}

/*
************************** LITTLE BIT OPTIMIZED **************************

void add(vector<vector<int>> &board,vector<vector<int>> &ans,int n) // T(n!)
{
    vector<int> temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool if_poss(int row, int col, vector<vector<int>> &board, int n, unordered_map<int,bool> &crow, unordered_map<int,bool> &drow, unordered_map<int,bool> &udrow)
{
    // checking row
    if(crow[row])
    {
        return 0;
    }
    // checking diagonal
    // upper diagonal
    if(udrow[(n - 1) + (col - row)])
    {
        return 0;
    }
    // lower daigonal
    if(drow[row + col])
    {
        return 0;
    }

    return 1;
}

void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n, unordered_map<int,bool> &crow, unordered_map<int,bool> &drow, unordered_map<int,bool> &udrow)
{
    if (col == n)
    {
        add(board,ans,n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (if_poss(row, col, board, n, crow, drow, udrow))
        {
            board[row][col] = 1;
            crow[row] = 1;
            drow[row + col] = 1;
            udrow[(n - 1) + (col - row)] = 1;

            solve(col + 1, board, ans, n, crow, drow, udrow);

            board[row][col] = 0;
            crow[row] = 0;
            drow[row + col] = 0;
            udrow[(n - 1) + (col - row)] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));

    unordered_map<int,bool> crow;
    unordered_map<int,bool> drow;
    unordered_map<int,bool> udrow;

    solve(0, board, ans, n, crow, drow, udrow);
    return ans;
}
*/
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ans = N_queen(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}