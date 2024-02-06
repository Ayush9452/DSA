#include <bits/stdc++.h>
using namespace std;

// N meetings in one room
static bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second < b.second)
    {
        return 1;
    }
    return 0;
}

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({start[i], end[i]});
    }
    sort(v.begin(), v.end(), comp);

    int count = 1;
    int starttime = v[0].first;
    int endtime = v[0].second;

    for (int i = 1; i < n; i++)
    {
        if (v[i].first > endtime)
        {
            count++;
            starttime = v[i].first;
            endtime = v[i].second;
        }
    }

    return count;
}

// Shop in Candy Store
vector<int> candyStore(int c[], int N, int K)
{
    sort(c, c + N);

    int j = N;
    vector<int> ans(2, 0);

    for (int i = 0; i < j; i++)
    {
        ans[0] += c[i];
        j -= K;
    }

    j = 0;
    for (int i = N - 1; i >= j; i--)
    {
        ans[1] += c[i];
        j += K;
    }

    return ans;
}

// Check if it is possible to survive on Island
int minimumDays(int S, int N, int M)
{
    int sunday = S / 7;
    int buying = S - sunday;

    int ans = (S * M) / N;

    if ((S * M) % N != 0)
    {
        ans++;
    }

    if (ans <= buying)
    {
        return ans;
    }
    return -1;
}

//
// KHUD S KIYA THA

// string reverseWords(string S)
// {
//     // code here
//     stack<string> st;
//     string temp = "";

//     for (int i = 0; i < S.length(); i++)
//     {
//         if (S[i] == '.')
//         {
//             st.push(temp + '.');
//             temp = "";
//             continue;
//         }
//         temp += S[i];
//     }
//     st.push(temp + '.');

//     string ans = "";
//     while (!st.empty())
//     {
//         ans += st.top();
//         st.pop();
//     }
//     ans[ans.length() - 1] = '\0';

//     return ans;
// }

// -------------- GOOD SOLUTION -------------------
string reverseWords(string S)
{
    // code here
    string ans = "";
    string temp = "";

    for (int i = S.length() - 1; i >= 0; i--)
    {
        if (S[i] == '.')
        {
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans.push_back('.');
            temp = "";
        }
        else
        {
            temp.push_back(S[i]);
        }
    }

    reverse(temp.begin(), temp.end());
    ans += temp;

    return ans;
}

// Chocolate Distribution Problem
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());

    int i = 0;
    int j = m - 1;

    long long ans = INT_MAX;

    while (j < n)
    {
        ans = min(ans, a[j++] - a[i++]);
    }

    return ans;
}

// Minimum Cost of ropes
long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> p;
    for (int i = 0; i < n; i++)
    {
        p.push(arr[i]);
    }
    long long ans = 0;
    while (p.size() > 1)
    {
        long long first, second;
        first = p.top();
        p.pop();
        second = p.top();
        p.pop();

        long long sum = first + second;
        p.push(sum);

        ans += sum;
    }
    return ans;
}

// Huffman Encoding         << VERY VERY VERY IMPORTANT >>  { GRAPH, PRIORITY_QUEUE }

//              O(n log n)          S(n)
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class cmp
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

void traversal(node *root, vector<string> &ans, string temp)
{
    if (root == NULL)
    {
        return;
    }

    if (root->right == NULL && root->left == NULL)
    {
        ans.push_back(temp);
        return;
    }
    traversal(root->left, ans, temp + '0');
    traversal(root->right, ans, temp + '1');
}

vector<string> huffmanCodes(string S, vector<int> f, int N)
{

    priority_queue<node *, vector<node *>, cmp> pq;
    for (int i = 0; i < N; i++)
    {
        node *temp = new node(f[i]);
        pq.push(temp);
    }

    while (pq.size() > 1)
    {
        node *left = pq.top();
        pq.pop();

        node *right = pq.top();
        pq.pop();

        node *temp = new node(left->data + right->data);
        temp->left = left;
        temp->right = right;
        pq.push(temp);
    }

    node *root = pq.top();
    vector<string> ans;
    string temp = "";

    traversal(root, ans, temp);

    return ans;
}

// Fractional Knapsack

struct Item
{
    int value;
    int weight;
};

static bool cmp2(pair<double, Item> &a, pair<double, Item> &b)
{
    return a.first > b.first;
}

// Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{
    vector<pair<double, Item>> v;
    for (int i = 0; i < n; i++)
    {
        double perunit = ((double)arr[i].value) / arr[i].weight;
        v.push_back({perunit, arr[i]});
    }
    sort(v.begin(), v.end(), cmp2);

    int w = W;
    double ans = 0;
    for (int i = 0; i < n && w > 0; i++)
    {
        if (w >= v[i].second.weight)
        {
            ans += v[i].second.value;
            w -= v[i].second.weight;
        }
        else
        {
            ans += (v[i].first * w);
            w = 0;
        }
    }

    return ans;
}

int main()
{

    return 0;
}