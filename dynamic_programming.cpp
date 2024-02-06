#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

// LECTURE 102
// using top-down approach (recursion + memorization)  O(N)  S(N) + S(N)
int febonacci(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = febonacci(n - 1, dp) + febonacci(n - 2, dp);
    return dp[n];
}

// using bottom - up approach (Tabulation)    O(N)  S(N)
int fibo(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Space optimization   O(N)  S(1)
int fibos(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int prev1 = 0;
    int prev2 = 1;
    int curr;

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

// LECTURE 103
int countdistinctways(int n, int N, vector<int> &dp)
{
    if (n == N)
    {
        return 1;
    }
    if (n > N)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = (countdistinctways(n + 1, N, dp) + countdistinctways(n + 2, N, dp)) % MOD;
    return dp[n];
}

int countDistinctWays(int nStairs)
{
    int ans = 0;
    vector<int> dp(nStairs, -1);
    ans = countdistinctways(0, nStairs, dp);
    return ans;
}

// Min Cost Climbing Stairs
// using only recursion
int price(int n, vector<int> &cost)
{
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }

    return (min(price(n - 1, cost), price(n - 2, cost)) + cost[n]);
}

// using recursion + memorization
int price(int n, vector<int> &cost, vector<int> &dp)
{
    if (n == 0)
    {
        dp[0] = cost[0];
        return dp[0];
    }
    if (n == 1)
    {
        dp[1] = cost[1];
        return dp[1];
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (min(price(n - 1, cost, dp), price(n - 2, cost, dp)) + cost[n]);
    return dp[n];
}

// using tabulation
int price(vector<int> &cost)
{
    int n = cost.size();

    vector<int> dp(n + 1, -1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }

    return min(dp[n - 1], dp[n - 2]);
}

// space optimaization
int price4(vector<int> &cost)
{
    int n = cost.size();

    int prev1 = cost[0];
    int prev2 = cost[1];
    int curr;

    for (int i = 2; i < n; i++)
    {
        curr = min(prev1, prev2) + cost[i];
        prev1 = prev2;
        prev2 = curr;
    }

    return min(prev1, prev2);
}

int minCostClimbingStairs(vector<int> &cost)
{
    int N = cost.size();
    vector<int> dp(N, 0);
    int ans = min(price(N - 1, cost, dp), price(N - 2, cost, dp));
    return ans;
}

// LECTURE 104
// Minimum Number of Coins
// using reccursion
int mincoin(int n, vector<int> &coins)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = mincoin(n - coins[i], coins);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    return mini;
}

// using reccursion + memorizaion
int mincoin(int n, vector<int> &coins, vector<int> &dp)
{
    if (n == 0)
    {
        dp[n] = 0;
        return dp[n];
    }
    else if (n < 0)
    {
        return INT_MAX;
    }
    // if already processed
    if (dp[n] != -1)
    {
        return dp[n];
    }
    // if not processed
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = mincoin(n - coins[i], coins, dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    dp[n] = mini;
    return dp[n];
}

// tabulation
int mincoin(vector<int> &coins, int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if ((i - coins[j]) >= 0 && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
            }
        }
    }
    return dp[n];
}

// space optimaization NOT POSSIBLE

// LECTURE 105
//  Maximum Sum of Non-Adjacent Elements
// only using recurssion
int maxsum(vector<int> &num, int i)
{
    if (i >= num.size())
    {
        return 0;
    }
    // include
    int ansa = maxsum(num, i + 2) + num[i];
    // exclude
    int ansb = maxsum(num, i + 1);

    return max(ansa, ansb);
}

// using recurrsion and memorization
int maxsum(vector<int> &num, int i, vector<int> &dp)
{
    if (i >= num.size())
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    // include
    int ansa = maxsum(num, i + 2, dp) + num[i];
    // exclude
    int ansb = maxsum(num, i + 1, dp);

    dp[i] = max(ansa, ansb);
    return dp[i];
}

// tabulation
int maxsum(vector<int> &num)
{
    int n = num.size();
    vector<int> dp(n, 0);
    dp[0] = num[0];

    for (int i = 1; i < n; i++)
    {
        // include
        int ansa = dp[i - 2] + num[i];
        int ansb = dp[i - 1];

        dp[i] = max(ansa, ansb);
    }
    return dp[n - 1];
}

// space optimization
int maxsum2(vector<int> &num)
{
    int n = num.size();

    int prev1 = 0;
    int prev2 = num[0];

    for (int i = 1; i < n; i++)
    {
        int ansa = prev1 + num[i];
        int ansb = prev2;
        int curr = max(ansa, ansb);

        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

// LECTURE 106
// house robbery
long long int solve(vector<int> &num)
{
    int n = num.size();

    long long int prev1 = 0;
    long long int prev2 = num[0];

    for (int i = 1; i < n; i++)
    {
        long long int ansa = prev1 + num[i];
        long long int ansb = prev2;
        long long int curr = max(ansa, ansb);

        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

long long int houseRobber(vector<int> &value)
{
    int n = value.size();

    if (n == 1)
    {
        return value[0];
    }

    vector<int> case1, case2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            case2.push_back(value[i]);
        }
        if (i != n - 1)
        {
            case1.push_back(value[i]);
        }
    }

    return max(solve(case1), solve(case2));
}

// LECTURE 107
//  Cut Rod into Segments of X, Y, Z
// using only recurrsion
int segments(int l, int x, int y, int z)
{
    if (l == 0)
    {
        return 0;
    }
    if (l < 0)
    {
        return INT_MIN;
    }

    int a = segments(l - x, x, y, z) + 1;
    int b = segments(l - y, x, y, z) + 1;
    int c = segments(l - z, x, y, z) + 1;

    return max(a, max(b, c));
}

// using recursion + memorization
int segments(int l, int x, int y, int z, vector<int> &dp)
{
    if (l == 0)
    {
        return 0;
    }
    if (l < 0)
    {
        return INT_MIN;
    }
    if (dp[l] > 0)
    {
        return dp[l];
    }

    int a = segments(l - x, x, y, z, dp) + 1;
    int b = segments(l - y, x, y, z, dp) + 1;
    int c = segments(l - z, x, y, z, dp) + 1;

    dp[l] = max(a, max(b, c));
    return dp[l];
}

// using tabulation
int segmentstab(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0 && dp[i - x] != -1)
            dp[i] = max(dp[i], dp[i - x] + 1);

        if (i - y >= 0 && dp[i - y] != -1)
            dp[i] = max(dp[i], dp[i - y] + 1);

        if (i - z >= 0 && dp[i - z] != -1)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }
    return dp[n];
}

// sapce optimization NOT POSSIBLE

// LECTURE 108
// using recurssion only
long long int countdearrange(int n)
{
    if (n == 1 || n == 0)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    long long int ans = (n - 1) * (countdearrange(n - 2) + countdearrange(n - 1));
    return ans;
}

// using recurssion + memorization
long long int countdearrange(int n, vector<long long int> &dp)
{
    if (n == 1 || n == 0)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = (n - 1) * (countdearrange(n - 2, dp) + countdearrange(n - 1, dp));

    return dp[n];
}

// using tabulation
long long int countdearrange2(int n)
{
    if (n == 1 || n == 0)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    vector<long long int> dp(n + 1, 0);
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
}

// space optimization
long long int count2(int n)
{
    if (n == 1 || n == 0)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    long long int prev1 = 0;
    long long int prev2 = 1;

    for (int i = 3; i <= n; i++)
    {
        long long int curr = (i - 1) * (prev2 + prev1);

        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

// LECTURE 109
// Painting Fence Algorithm
int mul(int a, int b)
{
    return (((a % MOD) * 1LL * (b % MOD))) % MOD;
}

int add(int a, int b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

// using recurssion only
int noofways(int n, int k)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return mul(k, k);
    }

    return add(mul(k - 1, noofways(n - 1, k)), mul(k - 1, noofways(n - 2, k)));
}

// using recurssion + memorization
int noofways(int n, int k, vector<int> &dp)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return mul(k, k);
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = add(mul(k - 1, noofways(n - 1, k, dp)), mul(k - 1, noofways(n - 2, k, dp)));

    return dp[n];
}

// using tabulation
int noofways2(int n, int k)
{
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = mul(k, k);

    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(mul(k - 1, dp[i - 1]), mul(k - 1, dp[i - 2]));
    }

    return dp[n];
}

// space optimaization
int noofways3(int n, int k)
{
    if (n == 1)
    {
        return k;
    }

    int prev1 = k;
    int prev2 = mul(k, k);

    for (int i = 3; i <= n; i++)
    {
        int ans = add(mul(k - 1, prev1), mul(k - 1, prev2));
        prev1 = prev2;
        prev2 = ans;
    }

    return prev2;
}

// LECTURE 110
// 0/1 KnapSack Problem || learn 2-D DP Concept
// using recursion only                      O((n * w) ^ 2)  S(n * w)
int knapsak(vector<int> &weight, vector<int> &val, int n, int w, int i)
{
    if (i == n - 1)
    {
        if (w >= weight[n - 1])
        {
            return val[n - 1];
        }
        return 0;
    }

    int incl = 0;
    if (w >= weight[i])
    {
        incl = val[i] + knapsak(weight, val, n, w - weight[i], i + 1);
    }
    int excl = knapsak(weight, val, n, w, i + 1);

    return max(incl, excl);
}

// using recursion + memorization                  O(n * w)  S(n * w) + s(n * w)
int knapsak(vector<int> &weight, vector<int> &val, int n, int w, int i, vector<vector<int>> &dp)
{
    if (i == n - 1)
    {
        if (w >= weight[n - 1])
        {
            return val[n - 1];
        }
        return 0;
    }

    if (dp[i][w] != -1)
    {
        return dp[i][w];
    }

    int incl = 0;
    if (w >= weight[i])
    {
        incl = val[i] + knapsak(weight, val, n, w - weight[i], i + 1);
    }
    int excl = knapsak(weight, val, n, w, i + 1);

    dp[i][w] = max(incl, excl);

    return dp[i][w];
}

// using tabulation                         O(n * w)  S(n * w)
int knapsaktab(vector<int> &weight, vector<int> &val, int n, int w)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int i = weight[0]; i <= w; i++)
    {
        dp[0][i] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int incl = 0;
            if (j >= weight[i])
            {
                incl = val[i] + dp[i - 1][j - weight[i]];
            }
            int excl = dp[i - 1][j];
            dp[i][j] = max(incl, excl);
        }
    }

    return dp[n - 1][w];
}

// space optimization                       O(n * w)    S(2w)
int knapsack(vector<int> &weight, vector<int> &val, int n, int w)
{
    vector<int> prev(w + 1, 0);
    for (int i = weight[0]; i <= w; i++)
    {
        prev[i] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(w + 1, 0);
        for (int j = 0; j <= w; j++)
        {
            int incl = 0;
            if (j >= weight[i])
            {
                incl = val[i] + prev[j - weight[i]];
            }
            int excl = prev[j];
            curr[j] = max(incl, excl);
        }
        prev = curr;
    }
    return prev[w];
}

// more space optimized                         O(n * w)    S(w)
int knapsack2(vector<int> &weight, vector<int> &val, int n, int w)
{
    vector<int> prev(w + 1, 0);
    for (int i = weight[0]; i <= w; i++)
    {
        prev[i] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = w; j >= 0; j--)
        {
            int incl = 0;
            if (j >= weight[i])
            {
                incl = val[i] + prev[j - weight[i]];
            }
            int excl = prev[j];
            prev[j] = max(incl, excl);
        }
    }

    return prev[w];
}

// LECTURE 111
// Combination Sum IV Problem
// using recursion only                 O(expo)
int solve(vector<int> &num, int tar)
{
    if (tar < 0)
    {
        return 0;
    }
    if (tar == 0)
    {
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solve(num, tar - num[i]);
    }

    return ans;
}

// using recursion + memorization               O(tar * tar)   S(tar)
int solve(vector<int> &num, int tar, vector<int> &dp)
{
    if (tar < 0)
    {
        return 0;
    }
    if (tar == 0)
    {
        return 1;
    }

    if (dp[tar] != -1)
    {
        return dp[tar];
    }

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solve(num, tar - num[i], dp);
    }

    dp[tar] = ans;
    return dp[tar];
}

// using tabulation                     O(tar*num.size)    S(tar)
int solvetab(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= tar; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i >= num[j])
            {
                dp[i] += dp[i - num[j]];
            }
        }
    }

    return dp[tar];
}

// space optimization NOT POSSIBLE

// LECTURE 112
// Perfect Squares Problem
// using only recursion
int solve(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int ans = n;

    for (int j = 1; j * j <= n; j++)
    {
        int incl = solve(n - (j * j)) + 1;
        ans = min(incl, ans);
    }
    return ans;
}

// using recursion + memorization
int solve(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        int incl = solve(n - (i * i), dp) + 1;
        ans = min(incl, ans);
    }

    dp[n] = ans;
    return dp[n];
}

// using tabulation
int solvetab(int n)
{
    vector<int> dp(n + 1, n);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i - (j * j)] + 1, dp[i]);
        }
    }
    return dp[n];
}

// space optimaization NOT POSSIBLE

// LECTURE 113
// Minimum Cost for Tickets
// using recursion only
int solve(int n, vector<int> &days, vector<int> &cost, int i)
{
    if (i >= n)
    {
        return 0;
    }
    int opt1 = cost[0] + solve(n, days, cost, i + 1);

    int j;
    for (j = i; j < n && (days[i] + 7) > days[j]; j++)
        ;
    int opt2 = cost[1] + solve(n, days, cost, j);

    for (j = i; j < n && (days[i] + 30) > days[j]; j++)
        ;
    int opt3 = cost[2] + solve(n, days, cost, j);

    return min(opt1, min(opt2, opt3));
}

// using recursion + memorization
int solve(int n, vector<int> &days, vector<int> &cost, int i, vector<int> &dp)
{
    if (i >= n)
    {
        return 0;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    int opt1 = cost[0] + solve(n, days, cost, i + 1, dp);

    int j;
    for (j = i; j < n && days[j] < days[i] + 7; j++)
        ;
    int opt2 = cost[1] + solve(n, days, cost, j, dp);

    for (j = i; j < n && days[j] < days[i] + 30; j++)
        ;
    int opt3 = cost[2] + solve(n, days, cost, j, dp);

    dp[i] = min(opt1, min(opt2, opt3));
    return dp[i];
}

// using tabulation
int solvetab(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        //         day1
        int opt1 = cost[0] + dp[i + 1];

        //         day7
        int j;
        for (j = i; j < n && days[j] < days[i] + 7; j++)
            ;
        int opt2 = cost[1] + dp[j];

        //         day30
        for (j = i; j < n && days[j] < days[i] + 30; j++)
            ;
        int opt3 = cost[2] + dp[j];

        dp[i] = min(opt1, min(opt2, opt3));
    }

    return dp[0];
}

// LECTURE 114 (space optimizaton of above problem)  << VERY VERY IMPORTANT >>
int solve2(int n, vector<int> &days, vector<int> &cost)
{
    int ans = 0;
    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    for (auto day : days)
    {
        while (!month.empty() && (month.front().first + 30 <= day))
        {
            month.pop();
        }
        while (!week.empty() && (week.front().first + 7 <= day))
        {
            week.pop();
        }

        month.push({day, ans + cost[2]});
        week.push({day, ans + cost[1]});

        ans = min(ans + cost[0], min(month.front().second, week.front().second));
    }
    return ans;
}

// LECTURE 115
// Largest Square area in Matrix
// using recursion only             O(expo)     S(expo)
int solve(vector<vector<int>> &mat, int i, int j, int &maxi)
{
    if (i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }

    int left = solve(mat, i, j + 1, maxi);
    int dia = solve(mat, i + 1, j + 1, maxi);
    int right = solve(mat, i + 1, j, maxi);

    if (mat[i][j] == 1)
    {
        int ans = 1 + min(left, min(dia, right));
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}

// using recursion + memorization           O(n * m)    S(n * m)
int solve(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp, int &maxi)
{
    if (i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int left = solve(mat, i, j + 1, dp, maxi);
    int dia = solve(mat, i + 1, j + 1, dp, maxi);
    int right = solve(mat, i + 1, j, dp, maxi);

    if (mat[i][j] == 1)
    {
        dp[i][j] = 1 + min(left, min(dia, right));
        maxi = max(dp[i][j], maxi);
        return dp[i][j];
    }
    else
    {
        return dp[i][j] = 0;
    }
}

// using tabulation                  O(n * m)    S(n * m)
int solve(vector<vector<int>> &mat, int &maxi)
{
    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {

            int right = dp[i][j + 1];
            int dia = dp[i + 1][j + 1];
            int down = dp[i + 1][j];

            if (mat[i][j] == 1)
            {
                dp[i][j] = 1 + min(right, min(dia, down));
                maxi = max(maxi, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[0][0];
}

// space optimized               O(n * m)    S(m)
int solveso(vector<vector<int>> &mat, int &maxi)
{
    int row = mat.size();
    int col = mat[0].size();

    vector<int> cur(col + 1, 0);
    vector<int> next(col + 1, 0);

    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int left = cur[j + 1];
            int dia = next[j + 1];
            int down = next[j];

            if (mat[i][j] == 1)
            {
                cur[j] = 1 + min(left, min(dia, down));
                maxi = max(maxi, cur[j]);
            }
            else
            {
                cur[j] = 0;
            }
        }
        next = cur;
    }

    return next[0];
}

// space optimized           O(n * m)    S(1)       {H.W.}
int solve4(vector<vector<int>> &mat, int n, int m, int &maxi)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int left = (j < m - 1) ? mat[i][j + 1] : 0;
            int dia = ((j < m - 1) && (i < n - 1)) ? mat[i + 1][j + 1] : 0;
            int down = (i < n - 1) ? mat[i + 1][j] : 0;

            if (mat[i][j] == 1)
            {
                mat[i][j] = 1 + min(left, min(dia, down));
                maxi = max(maxi, mat[i][j]);
            }
            else
            {
                mat[i][j] = 0;
            }
        }
    }
    return mat[0][0];
}

// LECTURE 116
// MATRIX CHAIN MULTIPLICATION (MCM PATTERN)
// Min Score Triangulation of Polygon
// using recursion only                   O(n!)
int solve(int s, int e, vector<int> &v)
{
    if (e == s + 1)
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int i = s + 1; i < e; i++)
    {
        ans = min(ans, (v[s] * v[e] * v[i]) + solve(s, i, v) + solve(i, e, v));
    }

    return ans;
}

// using recursion + memorization               O(n*n)          S(n*n)
int solve(int s, int e, vector<int> &v, vector<vector<int>> &dp)
{
    if (e == s + 1)
    {
        return dp[s][e] = 0;
    }

    if (dp[s][e] != -1)
    {
        return dp[s][e];
    }

    int ans = INT_MAX;
    for (int i = s + 1; i < e; i++)
    {
        ans = min(ans, (v[s] * v[e] * v[i]) + solve(s, i, v, dp) + solve(i, e, v, dp));
    }

    dp[s][e] = ans;
    return dp[s][e];
}

// using tabulation                 O(n*n)          S(n*n)
int solvetab(vector<int> &v)
{
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 2; j < n; j++)
        {

            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                ans = min(ans, (v[i] * v[j] * v[k]) + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = ans;
        }
    }

    return dp[0][n - 1];
}

// LECTURE 117
// Minimum Sideways Jump LeetCode
// using recursion only
int solve(int l, vector<int> &ob, int s)
{
    if (s == ob.size())
    {
        return 0;
    }

    if (ob[s + 1] != l)
    {
        return solve(l, ob, s + 1);
    }
    else
    {
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            if (i != l && ob[s] != i)
            {
                ans = min(ans, 1 + solve(i, ob, s));
            }
        }

        return ans;
    }
}

// using recursion + memorization                   O(9*n)  S(n*n)
int solve(int l, vector<int> &ob, int s, vector<vector<int>> &dp)
{
    if (s == ob.size() - 1)
    {
        return 0;
    }

    if (dp[l][s] != -1)
    {
        return dp[l][s];
    }

    if (ob[s + 1] != l)
    {
        return solve(l, ob, s + 1, dp);
    }
    else
    {
        int ans = INT_MAX;

        for (int i = 1; i <= 3; i++)
        {
            if (i != l && ob[s] != i)
            {
                ans = min(ans, 1 + solve(i, ob, s, dp));
            }
        }
        dp[l][s] = ans;
        return dp[l][s];
    }
}

// using tabulation                     O(9*n)         S(n*n)
int solvetab(vector<int> &ob)
{
    int n = ob.size() - 1;
    vector<vector<int>> dp(4, vector<int>(ob.size(), 1e9));
    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for (int curpos = n - 1; curpos >= 0; curpos--)
    {
        for (int curlane = 1; curlane <= 3; curlane++)
        {
            if (ob[curpos + 1] != curlane)
            {
                dp[curlane][curpos] = dp[curlane][curpos + 1];
            }
            else
            {
                int ans = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    // sideways jump
                    if (curlane != i && ob[curpos] != i)
                    {
                        ans = min(ans, 1 + dp[i][curpos + 1]);
                    }
                }
                dp[curlane][curpos] = ans;
            }
        }
    }
    return min(dp[2][0], min(dp[1][0] + 1, dp[3][0] + 1));
}

// space optimization                   O(9*n)      S(1)
int solveSO(vector<int> &ob)
{
    int n = ob.size();

    vector<int> cur(4, INT_MAX);
    vector<int> next(4, 0);

    for (int curpos = n - 2; curpos >= 0; curpos--)
    {
        for (int curlane = 1; curlane <= 3; curlane++)
        {
            if (ob[curpos + 1] != curlane)
            {
                cur[curlane] = next[curlane];
            }
            else
            {
                int ans = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    if (curlane != i && ob[curpos] != i)
                    {
                        ans = min(ans, 1 + next[i]);
                    }
                }
                cur[curlane] = ans;
            }
        }
        next = cur;
    }
    return min(next[2], min(next[1] + 1, next[3] + 1));
}

// LECTURE 118
// Reducing Dishes LeetCode
// using recursion only             O(expo)
int solve(int j, int n, vector<int> &sat, int t)
{
    if (j >= n)
    {
        return 0;
    }

    int ans = INT_MIN;

    // include
    int a = (t * sat[j]) + solve(j + 1, n, sat, t + 1);

    // exclude
    int b = solve(j + 1, n, sat, t);

    ans = max(ans, max(a, b));

    return ans;
}

// using recursion + memorization           O(n * n)        S(n * n)
int solve(vector<vector<int>> &dp, int i, int n, vector<int> &sat, int t)
{
    if (i >= n)
    {
        return 0;
    }

    if (dp[i][t] != -1)
    {
        return dp[i][t];
    }

    // include
    int a = (t * sat[i]) + solve(dp, i + 1, n, sat, t + 1);

    // exclude
    int b = solve(dp, i + 1, n, sat, t);

    dp[i][t] = max(a, b);
    return dp[i][t];
}

// using tabulation         O(n * n)        S(n * n)
int solve2(vector<int> &sat)
{
    int n = sat.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int t = i; t >= 0; t--)
        {
            int a = (sat[i] * (t + 1)) + dp[i + 1][t + 1];
            int b = dp[i + 1][t];

            dp[i][t] = max(a, b);
        }
    }
    return dp[0][0];
}

// space optimized          O(n * n)        S(2n)
int solveSO(vector<int> &sat)
{
    int n = sat.size();
    vector<int> next(n + 1, 0);
    vector<int> cur(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int t = i; t >= 0; t--)
        {
            int a = (sat[i] * (t + 1)) + next[t + 1];
            int b = next[t];

            cur[t] = max(a, b);
        }
        next = cur;
    }
    return next[0];
}

// space optimizes          O(n * n)        S(n)
int solveSO1(vector<int> &sat)
{
    int n = sat.size();
    vector<int> next(n + 1, 0);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int t = 1;
        for (int j = i; j < n; j++)
        {
            next[i] += (sat[j] * (t++));
        }
        ans = max(ans, next[i]);
    }
    return ans;
}

// space optimized (greedy method)          O(n)        S(1)
int solveSO2(vector<int> &sat)
{
    int ans = 0;
    int suf = 0;
    for (int i = sat.size() - 1; i >= 0; i--)
    {
        ans += ((i + 1) * sat[i]);
        suf += sat[i];
        if (suf < 0)
        {
            ans -= suf;
        }
    }
    return ans;
}

// LECTURE 119
// Longest Increasing Subsequence
// using recursion only             O(expo)
int LIS(int a[], int n, int curr, int last)
{
    if (curr == n)
    {
        return 0;
    }

    int incl = 0;
    if (last == -1 || a[curr] > a[last])
    {
        incl = 1 + LIS(a, n, curr + 1, curr);
    }
    int excl = LIS(a, n, curr + 1, last);

    return max(incl, excl);
}

// using recursion + memorization            O(n * n)        S(n * n)
int LIS(int a[], int n, int cur, int prev, vector<vector<int>> &dp)
{
    if (cur == n)
    {
        return 0;
    }

    if (dp[cur][prev + 1] != -1)
    {
        return dp[cur][prev + 1];
    }

    int incl = 0;
    if (prev == -1 || a[cur] > a[prev])
    {
        incl = 1 + LIS(a, n, cur + 1, cur, dp);
    }
    int excl = LIS(a, n, cur + 1, prev, dp);

    dp[cur][prev + 1] = max(incl, excl);
    return dp[cur][prev + 1];
}

// using tabulation             O(n * n)        S(n * n)
int solvetab(int a[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int cur = n - 1; cur >= 0; cur--)
    {
        for (int prev = cur - 1; prev >= -1; prev--)
        {
            int incl = 0;
            if (prev == -1 || a[cur] > a[prev])
            {
                incl = 1 + dp[cur + 1][cur + 1];
            }
            int excl = dp[cur + 1][prev + 1];
            dp[cur][prev + 1] = max(incl, excl);
        }
    }
    return dp[0][0];
}

// space optimized              O(n * n)        S(2*n)
int solveSO(int a[], int n)
{
    vector<int> currow(n + 1, 0);
    vector<int> nextrow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int incl = 0;
            if (prev == -1 || a[curr] > a[prev])
            {
                incl = 1 + nextrow[curr + 1];
            }
            int excl = nextrow[prev + 1];
            currow[prev + 1] = max(incl, excl);
        }
        nextrow = currow;
    }
    return nextrow[0];
}

// space optimized and optimal (binary search and DP)       O(nlogn)        S(n)
int solveoptimal(int a[], int n)
{
    vector<int> ans;
    ans.push_back(a[0]);

    for (int i = 1; i < n; i++)
    {
        if (ans.back() < a[i])
        {
            ans.push_back(a[i]);
        }
        else
        {
            // find index of just bada element in ans
            int pos = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[pos] = a[i];
        }
    }
    return ans.size();
}

// Russian Doll Envelopes               O(nlogn)        S(n)
static bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
    {
        return (a[1] > b[1]);
    }
    return (a[0] < b[0]);
}

int solve(vector<vector<int>> &env)
{
    int n = env.size();
    vector<int> ans;
    ans.push_back(env[0][1]);

    for (int i = 1; i < n; i++)
    {
        if (ans.back() < env[i][1])
        {
            ans.push_back(env[i][1]);
        }
        else
        {
            int pos = lower_bound(ans.begin(), ans.end(), env[i][1]) - ans.begin();
            ans[pos] = env[i][1];
        }
    }
    return ans.size();
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end(), comp);
    return solve(envelopes);
}

// LECTURE 120
// Maximum Height by Stacking Cuboid            <<  IMPORTNAT  >>
bool check(vector<int> base, vector<int> newbox)
{
    if (newbox[0] <= base[0] && newbox[1] <= base[1] && newbox[2] <= base[2])
    {
        return 1;
    }
    return 0;
}

// { USING ABOVE APPROACH }
int solve(int n, vector<vector<int>> &cub)
{
    vector<int> currow(n + 1, 0);
    vector<int> nextrow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int incl = 0;
            if (prev == -1 || check(cub[curr], cub[prev]))
            {
                incl = cub[curr][2] + nextrow[curr + 1];
            }
            int excl = nextrow[prev + 1];

            currow[prev + 1] = max(incl, excl);
        }
        nextrow = currow;
    }
    return nextrow[0];
}

int maxHeight(vector<vector<int>> &cuboids)
{
    for (auto &a : cuboids)
    {
        sort(a.begin(), a.end());
    }

    sort(cuboids.begin(), cuboids.end());

    return solve(cuboids.size(), cuboids);
}
// LECTURE 121
// Pizza with 3n Slices
// using recurstion only         O(expo)
int solve(int index, vector<int> &slice, int end, int n)
{
    if (n == 0 || index > end)
    {
        return 0;
    }

    int incl = slice[index] + solve(index + 2, slice, end, n - 1);
    int excl = solve(index + 1, slice, end, n);

    return max(incl, excl);
}

// using recurstion + memorization       O(k * k)    S(k * k)
int solve(int index, vector<int> &slice, int end, int n, vector<vector<int>> &dp)
{
    if (n == 0 || index > end)
    {
        return 0;
    }

    if (dp[index][n] != -1)
    {
        return dp[index][n];
    }

    int incl = slice[index] + solve(index + 2, slice, end, n - 1, dp);
    int excl = solve(index + 1, slice, end, n, dp);

    dp[index][n] = max(incl, excl);

    return dp[index][n];
}

// using tabulation         O(k * k)    S(k * k)
int solvetab(vector<int> &slice)
{
    int k = slice.size();
    vector<vector<int>> dp(k + 2, vector<int>(k + 2, 0));
    vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));

    for (int index = k - 2; index >= 0; index--)
    {
        for (int i = 1; i <= k / 3; i++)
        {
            int incl = slice[index] + dp[index + 2][i - 1];
            int excl = dp[index + 1][i];

            dp[index][i] = max(incl, excl);
        }
    }

    for (int index = k - 1; index >= 1; index--)
    {
        for (int i = 1; i <= k / 3; i++)
        {
            int incl = slice[index] + dp1[index + 2][i - 1];
            int excl = dp1[index + 1][i];

            dp1[index][i] = max(incl, excl);
        }
    }

    return max(dp[0][k / 3], dp1[1][k / 3]);
}

// space optimization       O(k * k)        S(k)
int solveSO(vector<int> &slices)
{
    int k = slices.size();
    vector<int> prev(k + 2, 0);
    vector<int> cur(k + 2, 0);
    vector<int> next(k + 2, 0);

    for (int index = k - 2; index >= 0; index--)
    {
        for (int i = 1; i <= k / 3; i++)
        {
            int incl = slices[index] + next[i - 1];
            int excl = cur[i];

            prev[i] = max(incl, excl);
        }
        next = cur;
        cur = prev;
    }

    vector<int> prev1(k + 2, 0);
    vector<int> cur1(k + 2, 0);
    vector<int> next1(k + 2, 0);

    for (int index = k - 1; index >= 1; index--)
    {
        for (int i = 1; i <= k / 3; i++)
        {
            int incl = slices[index] + next1[i - 1];
            int excl = cur1[i];

            prev1[i] = max(incl, excl);
        }
        next1 = cur1;
        cur1 = prev1;
    }

    return max(cur[k / 3], cur1[k / 3]);
}

int maxSizeSlices(vector<int> &slices)
{
    // int k = slices.size();
    // vector<vector<int>> dp(k,vector<int> ((k/3) + 1,-1));
    // int case1 = solve(0,slices,k - 2,k/3,dp);
    // vector<vector<int>> dp1(k,vector<int> ((k/3) + 1,-1));
    // int case2 = solve(1,slices,k - 1,k/3,dp1);
    // return max(case1,case2);
    return solveSO(slices);
}

// LECTURE 123
// Partition Equal Subset Sum
// using recursion only
int solve(int i, int a[], int n, int sum)
{
    if (i >= n)
    {
        return 0;
    }

    if (sum < 0)
    {
        return 0;
    }

    if (sum == 0)
    {
        return 1;
    }

    int incl = solve(i + 1, a, n, sum - a[i]);
    int excl = solve(i + 1, a, n, sum);

    return (incl | excl);
}

// using recursion + memorization
int solve(int i, int a[], int n, int sum, vector<vector<int>> &dp)
{
    if (i >= n || sum < 0)
    {
        return 0;
    }
    if (sum == 0)
    {
        return 1;
    }

    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }

    int incl = solve(i + 1, a, n, sum - a[i], dp);
    int excl = solve(i + 1, a, n, sum, dp);

    dp[i][sum] = incl | excl;

    return dp[i][sum];
}

// using tabulation
int solvetab(int a[], int n, int sum)
{
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= sum / 2; j++)
        {
            int incl = 0;
            if (j - a[i] >= 0)
            {
                incl = dp[i + 1][j - a[i]];
            }
            int excl = dp[i + 1][j];

            dp[i][j] = (incl | excl);
        }
    }

    return dp[0][sum / 2];
}

// space optimized
int solveSO(int a[], int n, int sum)
{
    vector<int> cur(sum + 1, 0);
    vector<int> next(sum + 1, 0);
    cur[0] = next[0] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= sum / 2; j++)
        {
            int incl = 0;
            if (j - a[i] >= 0)
            {
                incl = next[j - a[i]];
            }
            int excl = next[j];

            cur[j] = (incl | excl);
        }
        next = cur;
    }

    return next[sum / 2];
}

int equalPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }

    // it is impossible create ODD number from same two number
    if (sum & 1)
    {
        return 0;
    }

    // vector<vector<int>> dp(N,vector<int> (sum + 1,-1));

    // return solve(0,arr,N,sum/2,dp);

    return solveSO(arr, N, sum);
}

// LECTURE 124                  << IMPOTTANT >>
// Minimum Swaps to make Subsequences Increasing
// using recursion only
int solve(int i, vector<int> &num1, vector<int> &num2, int n, bool swapped)
{
    if (i == n)
    {
        return 0;
    }

    int prev1 = num1[i - 1];
    int prev2 = num2[i - 1];
    int ans = INT_MAX;

    // important
    if (swapped)
    {
        swap(prev1, prev2);
    }

    // noswap
    if (num1[i] > prev1 && num2[i] > prev2)
    {
        ans = solve(i + 1, num1, num2, n, 0);
    }

    // swap
    if (num1[i] > prev2 && num2[i] > prev1)
    {
        ans = min(ans, 1 + solve(i + 1, num1, num2, n, 1));
    }

    return ans;
}

// using recursion + memorization       O(n)      S(n)
int solve(int i, vector<int> &num1, vector<int> &num2, int n, bool swapped, vector<vector<int>> &dp)
{
    if (i == n)
    {
        return 0;
    }

    if (dp[i][swapped] != -1)
    {
        return dp[i][swapped];
    }

    int ans = 1e9;

    int prev1 = num1[i - 1];
    int prev2 = num2[i - 1];

    if (swapped)
    {
        swap(prev1, prev2);
    }

    if (num1[i] > prev1 && num2[i] > prev2)
    {
        ans = solve(i + 1, num1, num2, n, 0, dp);
    }

    if (num1[i] > prev2 && num2[i] > prev1)
    {
        ans = min(ans, 1 + solve(i + 1, num1, num2, n, 1, dp));
    }

    dp[i][swapped] = ans;

    return dp[i][swapped];
}

// using tabulation             O(n)   S(n)
int solvetab(vector<int> &num1, vector<int> &num2, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j >= 0; j--)
        {
            int ans = 1e9;
            int prev1 = num1[i - 1];
            int prev2 = num2[i - 1];

            if (j)
            {
                swap(prev1, prev2);
            }

            if (num1[i] > prev1 && num2[i] > prev2)
            {
                ans = dp[i + 1][0];
            }

            if (num1[i] > prev2 && num2[i] > prev1)
            {
                ans = min(ans, 1 + dp[i + 1][1]);
            }

            dp[i][j] = ans;
        }
    }
    return dp[1][0];
}

// space otpimization           O(n)    S(1)
int solveSO(vector<int> &num1, vector<int> &num2, int n)
{
    vector<int> cur(2, 0);
    vector<int> next(2, 0);

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j >= 0; j--)
        {
            int ans = 1e9;

            int prev1 = num1[i - 1];
            int prev2 = num2[i - 1];

            if (j)
            {
                swap(prev1, prev2);
            }

            if (num1[i] > prev1 && num2[i] > prev2)
            {
                ans = next[0];
            }

            if (num1[i] > prev2 && num2[i] > prev1)
            {
                ans = min(ans, 1 + next[1]);
            }

            cur[j] = ans;
        }
        next = cur;
    }
    return next[0];
}

// space optimization (same as above using int variable)   O(n)     S(1)
int solveSO2(vector<int> &num1, vector<int> &num2, int n)
{
    int swap1 = 0;
    int noswap = 0;
    int curswap = 0;
    int curnoswap = 0;

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j >= 0; j--)
        {
            int ans = 1e9;

            int prev1 = num1[i - 1];
            int prev2 = num2[i - 1];

            if (j)
            {
                swap(prev1, prev2);
            }

            if (num1[i] > prev1 && num2[i] > prev2)
            {
                ans = noswap;
            }

            if (num1[i] > prev2 && num2[i] > prev1)
            {
                ans = min(ans, 1 + swap1);
            }

            if (j)
            {
                curswap = ans;
            }
            else
            {
                curnoswap = ans;
            }
        }
        swap1 = curswap;
        noswap = curnoswap;
    }

    return min(swap1, noswap);
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    // so that we can start with index 1
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    int n = nums1.size();

    // vector<vector<int>> dp(n,vector<int> (2, -1));

    return solveSO2(nums1, nums2, n);
}

// DP + HASHING

// LECTURE 125
// Longest Arithmetic Subsequence               << VERY IMPORTANT >>    (new DP creation method)
// khud s kiya tha  ( MOST OPTIMIZED CODE SPACE AND TIMEWISE (a little slower than tabulation) )
int solve(int a[], int n)
{
    if (n <= 2)
    {
        return n;
    }

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int tempans = 2;
            int diff = a[j] - a[i];
            int first = a[i];
            for (int k = i - 1; k >= 0; k--)
            {
                if (first - a[k] == diff)
                {
                    tempans++;
                    first = a[k];
                }
            }
            ans = max(ans, tempans);
        }
    }
    return ans;
}

// using recursion only
int solve(int i, int a[], int diff)
{
    if (i < 0)
    {
        return 0;
    }

    int ans = 0;
    for (int j = i - 1; j >= 0; j--)
    {
        if (a[i] - a[j] == diff)
        {
            ans = max(ans, 1 + solve(j, a, diff));
        }
    }
    return ans;
}

// using recursion + memorization
int solve(int i, int a[], int diff, vector<vector<int>> &dp)
{
    if (i < 0)
    {
        return 0;
    }

    if (dp[i][diff] != -1)
    {
        return dp[i][diff];
    }

    int ans = 0;

    for (int j = i - 1; j >= 0; j--)
    {
        if (a[i] - a[j] == diff)
        {
            ans = max(ans, 1 + solve(j, a, diff, dp));
        }
    }
    dp[i][diff] = ans;

    return dp[i][diff];
}

// using recursion + memorization with unordered map DP     (slower than vector DP)
int solve(int i, int a[], int diff, unordered_map<int, int> dp[])
{
    if (i < 0)
    {
        return 0;
    }

    if (dp[i].count(diff))
    {
        return dp[i][diff];
    }

    int ans = 0;

    for (int j = i - 1; j >= 0; j--)
    {
        if (a[i] - a[j] == diff)
        {
            ans = max(ans, 1 + solve(j, a, diff, dp));
        }
    }
    dp[i][diff] = ans;

    return dp[i][diff];
}

// using tabulation
int solvetab(int a[], int n)
{
    unordered_map<int, int> dp[n + 1];
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = a[i] - a[j];
            int cnt = 1;

            if (dp[j].count(diff))
            {
                cnt = dp[j][diff];
            }

            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}

int lengthOfLongestAP(int a[], int n)
{
    if (n <= 2)
    {
        return n;
    }

    // vector<vector<int>> dp(n,vector<int> (a[n - 1] - a[0] + 1, -1));
    // unordered_map<int,int> dp[n + 1];

    // int ans = 0;
    // return solve(A,n);
    // for(int i = 0;i < n;i++)
    // {
    //     for(int j = i + 1;j < n;j++)
    //     {
    //         ans = max(ans,2 + solve(i,a,a[j] - a[i],dp));
    //     }
    // }
    return solvetab(a, n);
}

// LECTURE 126
// Longest AP with given Difference "d"
int longestSubsequence(vector<int> &arr, int diff)
{
    unordered_map<int, int> dp;
    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int temp = arr[i] - diff;
        int tempans = 0;

        if (dp.count(temp))
        {
            tempans = dp[temp];
        }

        dp[arr[i]] = 1 + tempans;

        ans = max(ans, dp[arr[i]]);
    }
    return ans;
}

// LECTURE 127          << IMPORTANT >>
// Unique Binary Search Trees  << DP + BINARY SEARCH TREE >>
// using recursion only
int solve(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (solve(i - 1) * solve(n - i));
    }

    return ans;
}

// using recursion + memoraization
int solve(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return dp[n] = 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (solve(i - 1, dp) * solve(n - i, dp));
    }

    dp[n] = ans;
    return dp[n];
}

// tabulation
int solvetab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int node = 2; node <= n; node++)
    {
        int ans = 0;
        for (int i = 1; i <= node; i++)
        {
            ans += (dp[i - 1] * dp[node - i]);
        }
        dp[node] = ans;
    }

    return dp[n];
}

// CATALON NUMBER
int fact(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }

    return n * fact(n - 1);
}

int catlonNumber(int n)
{
    return (fact(2 * n) / (fact(n + 1) * fact(n)));
}

int numTrees(int n)
{
    // vector<int> dp(n + 1,-1);
    return catlonNumber(n);
    // return solvetab(n);
}

// LECTURE 128
// DP + MERGE INTERVAL
// Guess Number Higher or Lower
// using recursion only
int solve(int start, int end)
{
    if (start >= end)
    {
        return 0;
    }

    int ans = INT_MAX;

    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solve(start, i - 1), solve(i + 1, end)));
    }

    return ans;
}

// using recursion + memorization
int solve(int start, int end, vector<vector<int>> &dp)
{
    if (start >= end)
    {
        return 0;
    }

    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }

    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solve(start, i - 1, dp), solve(i + 1, end, dp)));
    }

    dp[start][end] = ans;
    return dp[start][end];
}

// using tabulation
int solvetab(int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int start = n; start >= 1; start--)
    {
        for (int end = start; end <= n; end++)
        {
            if (start == end)
            {
                continue;
            }
            int ans = INT_MAX;
            for (int i = start; i <= end; i++)
            {
                ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
            }
            dp[start][end] = ans;
        }
    }

    return dp[1][n];
}

// space optimaization is not possible

int getMoneyAmount(int n)
{
    // vector<vector<int>> dp(n + 1,vector<int>(n + 1,-1));
    return solvetab(n);
}

// LECTURE 129
// Minimum Cost Tree From Leaf Values
// using recursion only

// << KHUD SE KIYA >>

// int maxa(int start,int end,vector<int> &arr)
// {
//     int ans = -1;
//     for(int i = start;i <= end;i++)
//     {
//         ans = max(ans,arr[i]);
//     }
//     return ans;
// }

// int solve(int start,int end,vector<int> &arr)
// {
//     if(end == start)
//     {
//         return 0;
//     }

//     int ans = INT_MAX;
//     for(int i = start;i < end;i++)
//     {
//         ans = min(ans,maxa(start,i,arr)*maxa(i + 1,end,arr) + solve(start,i,arr) + solve(i + 1,end,arr));
//     }

//     return ans;
// }

// using recursion only
int solve(int start, int end, vector<int> &arr, map<pair<int, int>, int> &maxa)
{
    if (start == end)
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int i = start; i < end; i++)
    {
        ans = min(ans, maxa[{start, i}] * maxa[{i + 1, end}] + solve(start, i, arr, maxa) +
                           solve(i + 1, end, arr, maxa));
    }

    return ans;
}

// using recursion + memorization
int solve(int start, int end, vector<int> &arr, map<pair<int, int>, int> &maxa, vector<vector<int>> &dp)
{
    if (start == end)
    {
        return 0;
    }

    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }

    int ans = INT_MAX;
    for (int i = start; i < end; i++)
    {
        ans = min(ans, maxa[{start, i}] * maxa[{i + 1, end}] + solve(start, i, arr, maxa, dp) +
                           solve(i + 1, end, arr, maxa, dp));
    }

    dp[start][end] = ans;

    return dp[start][end];
}

// almost O(n^3)
// using tabulation <<  H.W.  >>
int solvetab(vector<int> &arr, map<pair<int, int>, int> &maxa)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int start = n - 1; start >= 0; start--)
    {
        for (int end = start + 1; end < n; end++)
        {
            int tempans = 1e9;
            for (int i = start; i < end; i++)
            {
                tempans = min(tempans, (maxa[{start, i}] * maxa[{i + 1, end}]) + dp[start][i] +
                                           dp[i + 1][end]);
            }

            dp[start][end] = tempans;
        }
    }

    return dp[0][n - 1];
}

int mctFromLeafValues(vector<int> &arr)
{
    int n = arr.size();

    map<pair<int, int>, int> maxa;
    for (int i = 0; i < n; i++)
    {
        maxa[{i, i}] = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            maxa[{i, j}] = max(arr[j], maxa[{i, j - 1}]);
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    int ans = solvetab(arr, maxa);
    int ans = solvetab(arr, maxa);

    return ans;
}

// more optimized solutions are also available O(n^2) ( using heap ) and O(n) ( using stack )

// LECTURE 130
// Buy and Sell Stock [Part 1]
// Brute force method
int profit(vector<int> &price)
{
    int ans = 0;
    for (int i = 0; i < price.size(); i++)
    {
        for (int j = i + 1; j < price.size(); j++)
        {
            ans = max(ans, price[j] - price[i]);
        }
    }

    return ans;
}

// optimized method
int profit2(vector<int> &price)
{
    int ans = 0;
    int mini = price[0];

    for (int i = 1; i < price.size(); i++)
    {
        ans = max(ans, price[i] - mini);
        mini = min(mini, price[i]);
    }

    return ans;
}

// LECTURE 131
// Buy and Sell Stock [Part 2]
// using recursion only                                     O(expo)         S(expo)
int solve(int i, vector<int> &prices, int buy)
{
    if (i == prices.size())
    {
        return 0;
    }

    int incl, excl;

    if (buy)
    {
        incl = solve(i + 1, prices, 0) - prices[i];
        excl = solve(i + 1, prices, 1);
    }
    else
    {
        incl = prices[i] + solve(i + 1, prices, 1);
        excl = solve(i + 1, prices, 0);
    }

    return max(incl, excl);
}

// using tabulation + memorization              O(n)        S(n)
int solve(int i, vector<int> &prices, int buy, vector<vector<int>> &dp)
{
    if (i >= prices.size())
    {
        return 0;
    }

    if (dp[i][buy] != -1)
    {
        return dp[i][buy];
    }

    int incl, excl;

    if (buy)
    {
        incl = solve(i + 1, prices, 0, dp) - prices[i];
        excl = solve(i + 1, prices, 1, dp);
    }
    else
    {
        incl = prices[i] + solve(i + 1, prices, 1, dp);
        excl = solve(i + 1, prices, 0, dp);
    }

    dp[i][buy] = max(incl, excl);
    return dp[i][buy];
}
// using tabulation             O(n)        S(n)
int solvetab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 1; buy >= 0; buy--)
        {
            int incl, excl;
            if (buy)
            {
                incl = -prices[i] + dp[i + 1][0];
                excl = dp[i + 1][1];
            }
            else
            {
                incl = prices[i] + dp[i + 1][1];
                excl = dp[i + 1][0];
            }
            dp[i][buy] = max(incl, excl);
        }
    }

    return dp[0][1];
}

// space optimized              O(n)        S(1)
int solveSO(vector<int> &prices)
{
    int n = prices.size();
    vector<int> next(2, 0);
    vector<int> curr(2, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 1; buy >= 0; buy--)
        {
            int incl, excl;

            if (buy)
            {
                incl = -prices[i] + next[0];
                excl = next[1];
            }
            else
            {
                incl = prices[i] + next[1];
                excl = next[0];
            }

            curr[buy] = max(incl, excl);
        }
        next = curr;
    }

    return next[1];
}

// LECTURE 132
// Buy and Sell Stock [Part 3]
// using recurstion
int solve(int i, vector<int> &prices, int buy, int t)
{
    if (i == prices.size() || t > 2)
    {
        return 0;
    }

    int incl, excl;
    if (buy)
    {
        incl = -prices[i] + solve(i + 1, prices, 0, t + 1);
        excl = solve(i + 1, prices, 1, t);
    }
    else
    {
        incl = prices[i] + solve(i + 1, prices, 1, t);
        excl = solve(i + 1, prices, 0, t);
    }

    return max(incl, excl);
}

// using recursion + memorization           O(n)        S(n)
int solve(int i, vector<int> &prices, int buy, int t, vector<vector<vector<int>>> &dp)
{
    if (i == prices.size() || t > 2)
    {
        return 0;
    }

    if (dp[i][buy][t] != -1)
    {
        return dp[i][buy][t];
    }

    int incl, excl;

    if (buy)
    {
        incl = -prices[i] + solve(i + 1, prices, 0, t + 1, dp);
        excl = solve(i + 1, prices, 1, t, dp);
    }
    else
    {
        incl = solve(i + 1, prices, 1, t, dp) + prices[i];
        excl = solve(i + 1, prices, 0, t, dp);
    }

    return dp[i][buy][t] = max(incl, excl);
}

// using tabulation             O(n)        S(n)
int solvetab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(4, 0)));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int limit = 2; limit >= 0; limit--)
        {
            for (int buy = 1; buy >= 0; buy--)
            {
                int incl, excl;

                if (buy)
                {
                    incl = -prices[i] + dp[i + 1][0][limit + 1];
                    excl = dp[i + 1][1][limit];
                }
                else
                {
                    incl = prices[i] + dp[i + 1][1][limit];
                    excl = dp[i + 1][0][limit];
                }

                dp[i][buy][limit] = max(incl, excl);
            }
        }
    }

    return dp[0][1][0];
}

// space optimized          O(n)        S(1)
int solveSO(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> next(2, vector<int>(4, 0));
    vector<vector<int>> curr(2, vector<int>(4, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int limit = 2; limit >= 0; limit--)
        {
            for (int buy = 1; buy >= 0; buy--)
            {
                int incl, excl;

                if (buy)
                {
                    incl = -prices[i] + next[0][limit + 1];
                    excl = next[1][limit];
                }
                else
                {
                    incl = prices[i] + next[1][limit];
                    excl = next[0][limit];
                }

                curr[buy][limit] = max(incl, excl);
            }
        }
        next = curr;
    }

    return next[1][0];
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));
    // return solve(0,prices,1,0,dp);

    return solveSO(prices);
}

// LECTURE 133
// Buy and Sell Stock [Part 4]          [ SAME AS ABOVE BUT USING MODIFID LOGIC AND MODIFID QUESTION ]
// using recurstion
int solve(int i, int k, int operation, vector<int> &prices)
{
    if (i == prices.size() || operation == k * 2)
    {
        return 0;
    }

    int incl, excl;

    if (operation % 2 == 0) // even = buy is allowed
    {
        incl = -prices[i] + solve(i + 1, k, operation + 1, prices);
        excl = solve(i + 1, k, operation, prices);
    }
    else
    {
        incl = prices[i] + solve(i + 1, k, operation + 1, prices);
        excl = solve(i + 1, k, operation, prices);
    }

    return max(incl, excl);
}

// using recursion + memorization
int solve(int i, int operation, int k, vector<int> &prices, vector<vector<int>> &dp)
{
    if (i == prices.size() || operation == 2 * k)
    {
        return 0;
    }

    if (dp[i][operation] != -1)
    {
        return dp[i][operation];
    }

    int incl, excl;
    if (operation % 2 == 0)
    {
        incl = -prices[i] + solve(i + 1, operation + 1, k, prices, dp);
        excl = solve(i + 1, operation, k, prices, dp);
    }
    else
    {
        incl = prices[i] + solve(i + 1, operation + 1, k, prices, dp);
        excl = solve(i + 1, operation, k, prices, dp);
    }

    return dp[i][operation] = max(incl, excl);
}

// using tabulation
int solvetab(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>((2 * k) + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int operation = 2 * k - 1; operation >= 0; operation--)
        {
            int incl, excl;

            if (operation % 2 == 0)
            {
                incl = -prices[i] + dp[i + 1][operation + 1];
                excl = dp[i + 1][operation];
            }
            else
            {
                incl = prices[i] + dp[i + 1][operation + 1];
                excl = dp[i + 1][operation];
            }

            dp[i][operation] = max(incl, excl);
        }
    }

    return dp[0][0];
}

// space optimized
int solveSO(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<int> curr(2 * k + 1, 0);
    vector<int> next(2 * k + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int operation = 2 * k - 1; operation >= 0; operation--)
        {
            int incl, excl;

            if (operation % 2 == 0)
            {
                incl = -prices[i] + next[operation + 1];
                excl = next[operation];
            }
            else
            {
                incl = prices[i] + next[operation + 1];
                excl = next[operation];
            }

            curr[operation] = max(incl, excl);
        }
        next = curr;
    }

    return curr[0];
}

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    // vector<vector<int>> dp(n,vector<int> (2 * k, -1));
    // return solve(0,0,k,prices,dp);

    return solveSO(prices, k);
}

// LECTURE 134
// Buy and Sell Stock [Part 5]
// direct solved spaces optimized        [ similar to above problem just added fee to be paid per trnasaction ]
int solveSO(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<int> next(2, 0);
    vector<int> curr(2, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 1; buy >= 0; buy--)
        {
            int incl, excl;

            if (buy)
            {
                incl = -prices[i] + next[0] - fee;
                excl = next[1];
            }
            else
            {
                incl = prices[i] + next[1];
                excl = next[0];
            }

            curr[buy] = max(incl, excl);
        }
        next = curr;
    }

    return next[1];
}

int maxProfit(vector<int> &prices, int fee)
{
    return solveSO(prices, fee);
}

// SP on STRINGS
// LECTURE 135
// Longest Common Subsequence
// using recursion only
int solve(int i, int j, string &s1, string &s2)
{
    if (i == s1.length() || j == s2.length())
    {
        return 0;
    }

    if (s1[i] == s2[j])
    {
        return 1 + solve(i + 1, j + 1, s1, s2);
    }
    else
    {
        return max(solve(i + 1, j, s1, s2), solve(i, j + 1, s1, s2));
    }
}

// using recursion + memorization               O(min(n,m))         S(n * m)
int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i == s1.length() || j == s2.length())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s1[i] == s2[j])
    {
        return dp[i][j] = (1 + solve(i + 1, j + 1, s1, s2, dp));
    }
    else
    {
        return dp[i][j] = max(solve(i + 1, j, s1, s2, dp), solve(i, j + 1, s1, s2, dp));
    }
}

// using tabulation
int solvetab(string &s1, string &s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    return dp[0][0];
}

// space optimization               O(min(n,m))         S(max(n,m));
int solveSO(string &s1, string &s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    vector<int> curr(n2 + 1, 0);
    vector<int> next(n2 + 1, 0);

    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                curr[j] = 1 + next[j + 1];
            }
            else
            {
                curr[j] = max(curr[j + 1], next[j]);
            }
        }
        next = curr;
    }

    return curr[0];
}

int longestCommonSubsequence(string text1, string text2)
{
    // int n1 = text1.length();
    // int n2 = text2.length();
    // vector<vector<int>> dp(n1,vector<int> (n2,-1));
    // return solve(0,0,text1,text2,dp);

    return solveSO(text1, text2);
}

// SP on STRINGS
// LECTURE 136
// Longest Palindromic Subsequence     //SAME AS ABOVE ( just compare string to reverse of it )
int solve(string &s1, string &s2)
{
    vector<int> curr(s2.length() + 1, 0);
    vector<int> next(s2.length() + 1, 0);

    for (int i = s1.length() - 1; i >= 0; i--)
    {
        for (int j = s2.length() - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                curr[j] = 1 + next[j + 1];
            }
            else
            {
                curr[j] = max(curr[j + 1], next[j]);
            }
        }
        next = curr;
    }

    return next[0];
}

int longestPalindromeSubseq(string s)
{
    string s1 = s;
    reverse(s1.begin(), s1.end());

    return solve(s, s1);
}

// LECTURE 137
// EDIT Distance            << IMPORTANT >> { SPACE OPTIMIZATION PART }
// using recursion only
int solve(int i, int j, string &s1, string &s2)
{
    if (i == s1.length())
    {
        return s2.length() - j;
    }
    if (j == s2.length())
    {
        return s1.length() - i;
    }

    if (s1[i] == s2[j])
    {
        return solve(i + 1, j + 1, s1, s2);
    }
    else
    {
        // insert
        int insert = solve(i, j + 1, s1, s2);
        // delete
        int delet = solve(i + 1, j, s1, s2);
        // replace
        int replace = solve(i + 1, j + 1, s1, s2);

        return 1 + min(insert, min(delet, replace));
    }
}

// using recursion + memorization
int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i == s1.length())
    {
        return s2.length() - j;
    }
    if (j == s2.length())
    {
        return s1.length() - i;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s1[i] == s2[j])
    {
        return dp[i][j] = solve(i + 1, j + 1, s1, s2, dp);
    }
    else
    {
        int insert = solve(i, j + 1, s1, s2, dp);
        int delet = solve(i + 1, j, s1, s2, dp);
        int replace = solve(i + 1, j + 1, s1, s2, dp);

        return dp[i][j] = (1 + min(insert, min(delet, replace)));
    }
}

// using tabulation
int solvetab(string &s1, string &s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 0; i <= n2; i++)
    {
        dp[n1][i] = n2 - i;
    }
    for (int i = 0; i <= n1; i++)
    {
        dp[i][n2] = n1 - i;
    }

    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i][j + 1], min(dp[i + 1][j], dp[i + 1][j + 1]));
            }
        }
    }
    return dp[0][0];
}

// space optimized
int solveSO(string &s1, string &s2)
{
    // NEED TO BE HANDELED SEPERATELY
    if (s1.length() == 0)
    {
        return s2.length();
    }
    if (s2.length() == 0)
    {
        return s1.length();
    }

    int n1 = s1.length();
    int n2 = s2.length();

    vector<int> curr(n2 + 1, 0);
    vector<int> next(n2 + 1, 0);
    for (int i = 0; i < n2; i++) // IMPORTANT
    {
        next[i] = n2 - i;
    }

    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {

            curr[n2] = n1 - i; // IMPORTANT

            if (s1[i] == s2[j])
            {
                curr[j] = next[j + 1];
            }
            else
            {
                curr[j] = 1 + min(curr[j + 1], min(next[j], next[j + 1]));
            }
        }
        next = curr;
    }

    return next[0];
}

int minDistance(string word1, string word2)
{
    // int n1 = word1.length();
    // int n2 = word2.length();
    // vector<vector<int>> dp(n1,vector<int> (n2,-1));
    // return solve(0,0,word1,word2,dp);

    return solveSO(word1, word2);
}

// LECTURE 138
// Maximum Rectangle with all 1's           O(n * (m + m))
// revision of STACK
vector<int> smallest_prev(vector<int> &a, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && a[s.top()] >= a[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> smallest_up(vector<int> &a, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() != -1 && a[s.top()] >= a[i])
        {
            s.pop();
        }

        if (s.top() == -1)
        {
            ans[i] = n;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(i);
    }
    return ans;
}

int max_area(vector<int> &a, int n)
{
    vector<int> prev = smallest_prev(a, n);
    vector<int> up = smallest_up(a, n);

    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int b = up[i] - prev[i] - 1;
        ans = max(ans, a[i] * b);
    }
    return ans;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int ans = INT_MIN;
    vector<int> temp(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                temp[j]++;
            }
            else
            {
                temp[j] = 0;
            }
        }
        ans = max(ans, max_area(temp, m));
    }
    return ans;
}

// LECTURE 139
// Wildcard Pattern Matching
// using recursion only
bool solve(string &s1, string &s2, int i, int j)
{
    if (i < 0 && j < 0)
    {
        return 1;
    }
    if (i >= 0 && j < 0)
    {
        return 0;
    }
    if (i < 0 && j >= 0)
    {
        while (j >= 0)
        {
            if (s2[j] != '*')
            {
                return 0;
            }
            j--;
        }
        return 1;
    }

    // match
    if (s1[i] == s2[j] || s2[j] == '?')
    {
        return solve(s1, s2, i - 1, j - 1);
    }
    else if (s2[j] == '*')
    {
        return (solve(s1, s2, i, j - 1) | solve(s1, s2, i - 1, j));
    }

    return 0;
}

// using recusrtion + memorization
bool solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    // string & pattern both ends
    if (i < 0 && j < 0)
    {
        return 1;
    }
    // pattern end but string remains
    if (i >= 0 && j < 0)
    {
        return 0;
    }
    // string ends but pattern remains
    if (i < 0 && j >= 0)
    {
        while (j >= 0)
        {
            if (s2[j] != '*')
            {
                return 0;
            }
            j--;
        }
        return 1;
    }

    if (dp[i][j] != -1)
    {
        return (bool)dp[i][j];
    }

    // match
    if (s1[i] == s2[j] || s2[j] == '?')
    {
        return dp[i][j] = solve(s1, s2, i - 1, j - 1, dp);
    }
    else if (s2[j] == '*')
    {
        return dp[i][j] = (solve(s1, s2, i, j - 1, dp) | solve(s1, s2, i - 1, j, dp));
    }

    return dp[i][j] = 0;
}

// using tabualtion 
bool solvetab2(string &s1, string &s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n2; i++)
    {
        bool flag = 1;
        for (int j = 1; j <= i; j++)
        {
            if (s2[j - 1] != '*')
            {
                flag = 0;
                break;
            }
        }
        dp[0][i] = flag;
    }

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            bool ans = 0;
            if (s1[i - 1] == s2[j - 1] || s2[j - 1] == '?')
            {
                ans = dp[i - 1][j - 1];
            }
            if (s2[j - 1] == '*')
            {
                ans = dp[i][j - 1] | dp[i - 1][j];
            }
            dp[i][j] = ans;
        }
    }
    return dp[n1][n2];
}

// space optimized
bool solveSO2(string &s1, string &s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    vector<bool> prev(n2 + 1, 0);
    vector<bool> curr(n2 + 1, 0);
    prev[0] = 1;
    for (int i = 1; i <= n2; i++)
    {
        bool flag = 1;
        for (int j = 1; j <= i; j++)
        {
            if (s2[j - 1] != '*')
            {
                flag = 0;
                break;
            }
        }
        prev[i] = flag;
    }

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            bool ans = 0;
            if (s1[i - 1] == s2[j - 1] || s2[j - 1] == '?')
            {
                ans = prev[j - 1];
            }
            if (s2[j - 1] == '*')
            {
                ans = curr[j - 1] | prev[j];
            }
            curr[j] = ans;
        }
        prev = curr;
    }
    return prev[n2];
}

bool isMatch(string s, string p)
{
    int n1 = s.length();
    int n2 = p.length();

    // vector<vector<int>> dp(n1,vector<int> (n2,-1));
    // return solve(s,p,n1 - 1,n2 - 1,dp);
    return solveSO(s, p);
}

int main()
{
    int n;
    cin >> n;
    // vector<int> dp(n + 1, -1);
    // dp[0] = 0;
    // dp[1] = 1;
    // cout << fibos(n);
    return 0;
}