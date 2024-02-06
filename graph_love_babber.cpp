#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

/*
=================================== THEORY =====================================

    Node = stores data
    Edge = connectes node

    Undirected graph
        Degree = Degree of a node is number of edge connected to that node

    Directed graph
        Indegree = Indegree of a node is number of edges coming towards that node
        Outdegree = Outdegree of a node is number of edges going away from that node

    Weighted graph :- Edges carry some number like the length of the edge

    Path :- repition of node is not allowed (form one node to another node)

    Cyclic graph :- if node is already visited but after some time it appered again
                    then it is a cyclic graph

    Acyclic graph

====================== METHODES TO REPRESENT GRAPH =================================
    Adjacency matrix
    e.g.,
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},

    Adjacency list
    e.g.,
        1 -> 2, 3, 4
        2 -> 1, 4
        3 -> 1, 4, 5
        4 -> 1, 2, 3, 5
        5 -> 3, 4, 6, 7
        6 -> 5
        7 -> 5

*/

class graph
{
public:
    unordered_map<int, list<int>> adj;

    graph(int n) // insert all nodes with no edges
    {
        for (int i = 0; i < n; i++)
        {
            adj[i];
        }
    }

    void create_edge(int u, int v, bool direction)
    {
        // 0 = undirected
        // 1 = directed from u to v

        adj[u].push_back(v);

        if (!direction)
        {
            adj[v].push_back(u);
        }
    }

    void print_graph()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

// BFS traversal // for connected & unconnected graph
void bfs(unordered_map<int, set<int>> &g, unordered_map<int, bool> &visited, vector<int> &ans, int n)
{
    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto a : g[front])
        {
            if (!visited[a])
            {
                q.push(a);
                visited[a] = 1;
            }
        }
    }
    return;
}

// for connected & unconnected graph
void BFS(int vertex, vector<pair<int, int>> edges) // T(n + e) ,n = nodes ,e = edges
{
    vector<int> ans;
    unordered_map<int, set<int>> g;

    for (auto a : edges)
    {
        g[a.first].insert(a.second);
        g[a.second].insert(a.first);
    }

    unordered_map<int, bool> visited;
    for (int i = 0; i < vertex; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(g, visited, ans, i);
        }
    }

    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
}

// for connected & unconnected graph //purana
void dfs(graph &g, int n) // T() = S() = linear
{
    static unordered_map<int, bool> visited;
    if (!visited[n])
    {
        visited[n] = 1;
        cout << n << " ";
        for (auto a : g.adj[n])
        {
            dfs(g, a);
        }
    }
}

// ninja's question
void DFS(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited, vector<int> &temp,
         int n)
{
    if (!visited[n])
    {
        temp.push_back(n);
        visited[n] = 1;
        for (auto a : adj[n])
        {
            if (!visited[a])
            {
                DFS(adj, visited, temp, a);
            }
        }
    }
}

// for connected & unconnected graph
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    unordered_map<int, set<int>> adj;
    for (auto a : edges)
    {
        adj[a[0]].insert(a[1]);
        adj[a[1]].insert(a[0]);
    }

    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> temp;
            DFS(adj, visited, temp, i);
            ans.push_back(temp);
        }
    }
    return ans;
}

// CYCLE DETECTION IN UNDIRECTED GRAPH << IMPORTANT >>
// using BFS
bool checkcycle(unordered_map<int, list<int>> &g, unordered_map<int, bool> &visited, int n)
{
    unordered_map<int, int> parent;
    parent[n] = -1;

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto a : g[front])
        {
            if (visited[a] && parent[front] != a)
            {
                return 1;
            }
            else if (!visited[a])
            {
                q.push(a);
                visited[a] = 1;
                parent[a] = front;
            }
        }
    }
    return 0;
}

// using DFS
bool iscyclic2(unordered_map<int, list<int>> &g, unordered_map<int, bool> &visited, int parent, int n)
{
    visited[n] = 1;
    for (auto a : g[n])
    {
        if (!visited[a])
        {
            bool ans = iscyclic2(g, visited, n, a);
            if (ans)
            {
                return 1;
            }
        }
        else if (a != parent)
        {
            return 1;
        }
    }
    return 0;
}

bool iscyclic(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> graph;
    for (int i = 0; i < V; i++)
    {
        graph[i];
    }
    for (auto a : edges)
    {
        graph[a[0]].push_back(a[1]);
        graph[a[1]].push_back(a[0]);
    }

    unordered_map<int, bool> visited;
    bool ans;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            // ans = checkcycle(graph, visited, i);  , for DFS
            // for BFS
            ans = iscyclic2(graph, visited, -1, i);
            if (ans)
            {
                return 1;
            }
        }
    }
    return 0;
}

// CYCLE DETECTION IN DIRECTED GRAPH << IMPORTANT >>
// using BFS
bool iscyclepresent(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int n)
{
    unordered_map<int, bool> BFScall;

    queue<int> q;
    q.push(n);
    visited[n] = 1;
    BFScall[n] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto a : adj[front])
        {
            if (visited[a] && BFScall[a])
            {
                return 1;
            }
            else if (!visited[a])
            {
                q.push(a);
                visited[a] = 1;
                BFScall[a] = 1;
            }
        }
    }
    return 0;
}

// using DFS
bool iscyclepresent2(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited,
                     unordered_map<int, bool> &DFScall, int n)
{
    visited[n] = 1;
    DFScall[n] = 1;

    for (auto a : adj[n])
    {
        if (!visited[a])
        {
            bool ans = iscyclepresent2(adj, visited, DFScall, a);
            if (ans)
            {
                return 1;
            }
        }
        else if (DFScall[a])
        {
            return 1;
        }
    }
    DFScall[n] = 0;
    return 0;
}

bool iscycle(int n, int m, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = iscyclepresent(adj, visited, i);
            if (ans)
            {
                return 1;
            }
        }
    }
    return 0;
}

// TOPOLOGICAL SORT << IMPORTANT >>
// using DFS
void call(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, stack<int> &s, int n)
{
    visited[n] = 1;

    for (auto a : adj[n])
    {
        if (!visited[a])
        {
            call(adj, visited, s, a);
        }
    }
    s.push(n);
    return;
}

vector<int> topologicalsort(int n, int m, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }

    unordered_map<int, bool> visited;
    // for better time complexity we can use  vector<bool> visited(n)
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            call(adj, visited, s, i);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// USING KAHN'S ALGORITHM
vector<int> topologicalsort2(int n, int m, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }

    // unordered_map<int, int> degree;  LITTLE SLOW
    vector<int> degree(n);

    for (auto j : adj)
    {
        for (auto i : j.second)
        {
            degree[i]++;
        }
    }

    vector<int> ans;

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto a : adj[front])
        {
            degree[a]--;
            if (degree[a] == 0)
            {
                q.push(a);
            }
        }
    }

    return ans;
}

// CYCLE DETECTION IN DIRECTED GRAPH USING KAHN'S ALGORITHM
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    int m = edges.size();
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        adj[edges[i].first - 1].push_back(edges[i].second - 1);
    }

    // unordered_map<int, int> degree;  LITTLE SLOW
    vector<int> degree(n);

    for (auto j : adj)
    {
        for (auto i : j.second)
        {
            degree[i]++;
        }
    }

    int cnt = 0; // to check the validity of the topological sort

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        cnt++;

        for (auto a : adj[front])
        {
            degree[a]--;
            if (degree[a] == 0)
            {
                q.push(a);
            }
        }
    }

    if (cnt == n) // for valid topological sort
    {
        return 0;
    }
    return 1;
}

// SHORTEST PATH IN UNDIRECTED GRAPH
vector<int> shorest_path_using_DFS(int n, int m, vector<vector<int>> &edges, int s, int t)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
        adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    queue<int> q;
    q.push(0);
    parent[0] = -1;
    visited[0] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto a : adj[front])
        {
            if (!visited[a])
            {
                visited[a] = 1;
                parent[a] = front;
                q.push(a);
            }
        }
    }

    vector<int> ans;
    int start = t;

    while (start != s)
    {
        ans.push_back(start);
        start = parent[start];
    }
    ans.push_back(s);

    reverse(ans.begin(), ans.end());
    return ans;
}

//  SHORTEST PATH IN DIRECTED GRAPH
// dusara program bnnaa hua h "shortes_distance_in_directed_graph.cpp" naam s

int main()
{
    int n;
    // cout << "Enter the number of the nodes :- ";
    cin >> n;

    int m;
    // cout << "Enter the number of the edges :- ";
    cin >> m;

    graph g(n);
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        g.create_edge(u, v, 0); // Creating undirected graph
    }

    g.print_graph();

    cout << "\nDFS -> ";
    for (int i = 0; i < n; i++)
    {
        dfs(g, i);
    }
    cout << "\nBFS -> ";
    BFS(n, edges);
    return 0;
}