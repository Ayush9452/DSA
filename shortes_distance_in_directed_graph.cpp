#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    map<int, list<pair<int, int>>> adj;

    void setedges(int a, int b, int c)
    {
        adj[a].push_back({b, c});
    }

    void setedges2(int a, int b, int c)
    {
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    void showlist()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << '(' << j.first << ',' << j.second << "), ";
            }
            cout << endl;
        }
    }

    void topologicalsort(unordered_map<int, bool> &visited, int node, stack<int> &s)
    {
        visited[node] = 1;

        for (auto a : adj[node])
        {
            if (!visited[a.first])
            {
                topologicalsort(visited, a.first, s);
            }
        }
        s.push(node);
    }

    void get_shortest_path(int src, stack<int> &topo, vector<int> &dis)
    {
        dis[src] = 0;

        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();

            if (dis[top] != INT_MAX)
            {
                for (auto a : adj[top])
                {
                    if (dis[top] + a.second < dis[a.first])
                    {
                        dis[a.first] = dis[top] + a.second;
                    }
                }
            }
        }
    }

    // DIJKSTRA'S ALGORITHM << VERY VERY IMPORTANT >>
    void dijkstra_algo(int src, vector<int> &dis) // T(elog(v))  S(v+e)
    {
        dis[src] = 0;

        // creation of set on basic ({distance,node})
        set<pair<int, int>> s;
        s.insert({0, src});

        while (!s.empty())
        {
            auto top = *(s.begin());

            int nodedis = top.first;
            int node = top.second;

            s.erase(s.begin());

            for (auto a : adj[node])
            {
                if (dis[a.first] > nodedis + a.second)
                {
                    // is there record of same pair
                    auto record = s.find({dis[a.first], a.first});
                    if (record != s.end())
                    {
                        s.erase(record);
                    }

                    dis[a.first] = nodedis + a.second;
                    s.insert({dis[a.first], a.first});
                }
            }
        }
    }
};

// prim's algorithm  << VERY VERY IMPORTANT >>   O(n^2)
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)
    {
        int a = g[i].first.first;
        int b = g[i].first.second;
        int c = g[i].second;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<int> dis(n + 1);
    vector<bool> visit(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i < n + 1; i++)
    {
        dis[i] = INT_MAX;
        visit[i] = 0;
        parent[i] = -1;
    }
    int src = 1;
    dis[src] = 0;
    parent[src] = -1;

    vector<pair<pair<int, int>, int>> ans;

    for (int i = 1; i < n + 1; i++)
    {
        // finding minimum value  --  can be optimise using priority queue to O(nlogn)
        int mini = INT_MAX;
        int u;
        for (int j = 1; j <= n; j++)
        {
            if (visit[j] == 0 && mini > dis[j])
            {
                u = j;
                mini = dis[j];
            }
        }

        visit[u] = 1;

        for (auto it : adj[u])
        {
            int a = it.first;
            int b = it.second;

            if (!visit[a] && b < dis[a])
            {
                parent[a] = u;
                dis[a] = b;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        ans.push_back({{parent[i], i}, dis[i]});
    }
    return ans;
}

// Kruskal's Algorithm || Disjoint Set || Union by Rank & Path Compression  << IMPORTANT >>
void makeset(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int getparent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }

    return parent[node] = getparent(parent, parent[node]);
}

void unionset(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = getparent(parent, u);
    v = getparent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int minspanningtree(vector<vector<int>> &edges, int n) // O(nlogn) due to sorting only
{
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent, rank, n);

    int minweight = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = getparent(parent, edges[i][0]); // O(1)
        int v = getparent(parent, edges[i][1]);
        int w = edges[i][2];

        if (u != v)
        {
            minweight += w;
            unionset(u, v, parent, rank); // O(1)
        }
    }

    return minweight;
}

// Bridges In A Graph << IMPORTANT >>  O(N + E)  S(N)
void dfs(int node, int parent, vector<int> &low, vector<int> &disc, int &timer, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{
    vis[node] = 1;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!vis[nbr])
        {
            dfs(nbr, node, low, disc, timer, result, adj, vis);
            low[node] = min(low[node], low[nbr]);

            if (low[nbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int timer = 0;
    int parent = -1;
    vector<int> low(v);
    vector<int> disc(v);
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {
        low[i] = -1;
        disc[i] = -1;
    }

    vector<vector<int>> result;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, low, disc, timer, result, adj, vis);
        }
    }

    return result;
}

// Articulation Points in Graphs  O(N + E)  S(N)
void dfs2(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, int &timer, vector<int> &result, unordered_map<int, list<int>> &adj)
{
    int child = 0;
    vis[node] = 1;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!vis[nbr])
        {
            child++;
            dfs2(nbr, node, disc, low, vis, timer, result, adj);
            low[node] = min(low[node], low[nbr]);

            if (low[nbr] >= disc[node] && parent != -1)
            {
                result.push_back(node);
            }
        }
        else
        {
            low[node] = min(low[node], disc[nbr]);
        }
    }
    if (parent == -1 && child > 1)
    {
        result.push_back(node);
    }
}

vector<int> articulation(vector<vector<int>> &edges, int n, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int timer = 0;
    int parent = -1;
    vector<int> low(n);
    vector<int> disc(n);
    unordered_map<int, bool> vis;

    for (int i = 0; i < n; i++)
    {
        low[i] = -1;
        disc[i] = -1;
    }

    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs2(i, parent, disc, low, vis, timer, result, adj);
        }
    }

    return result;
}

//  Kosaraju's Algorithm for Strongly Connected Components  << VERY IMPORTANT >>  O(N + E)  S(N)
void topological(int n, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, stack<int> &topo)
{
    vis[n] = 1;
    for (auto nbr : adj[n])
    {
        if (!vis[nbr])
        {
            topological(nbr, adj, vis, topo);
        }
    }
    topo.push(n);
}

void dfs3(int n, vector<int> &temp, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{
    vis[n] = 1;
    temp.push_back(n);

    for (auto nbr : adj[n])
    {
        if (!vis[nbr])
        {
            dfs3(nbr, temp, adj, vis);
        }
    }
}

vector<vector<int>> kosaraju(vector<vector<int>> &edges, int n, int e)
{
    unordered_map<int, list<int>> adj, Tadj;

    for (int i = 0; i < e; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        adj[a].push_back(b);
        Tadj[b].push_back(a);
    }
    unordered_map<int, bool> vis;

    stack<int> topo;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topological(i, adj, vis, topo);
        }
    }

    vis.clear();

    vector<vector<int>> ans;
    while (!topo.empty())
    {
        int a = topo.top();
        topo.pop();

        if (!vis[a])
        {
            vector<int> temp;
            dfs3(a, temp, Tadj, vis);
            ans.push_back(temp);
        }
    }
    return ans;
}

// Bellmond ford   << IMPORTANT >>  O(N*M)
int belmond(int src, int dest, vector<vector<int>> &edges, int n, int m)
{
    vector<int> dis(n + 1, 1e9);
    dis[src] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a = edges[j][0];
            int b = edges[j][1];
            int wt = edges[j][2];

            if (dis[a] != 1e9 && dis[a] + wt < dis[b])
            {
                dis[b] = dis[a] + wt;
            }
        }
    }
    // TO DETECT NEGATIVE CYCLE
    bool flag = 0;
    for (int i = 0; i < m; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        int wt = edges[i][2];

        if (dis[a] != 1e9 && dis[a] + wt < dis[b])
        {
            flag = 1;
        }
    }
    if (!flag)
    {
        return dis[dest];
    }

    return -1;
}

int main()
{
    graph g;
    // g.setedges(0, 1, 5);
    // g.setedges(0, 2, 3);
    // g.setedges(1, 2, 2);
    // g.setedges(1, 3, 6);
    // g.setedges(2, 3, 7);
    // g.setedges(2, 4, 4);
    // g.setedges(2, 5, 2);
    // g.setedges(3, 4, -1);
    // g.setedges(4, 5, -2);

    g.setedges2(0, 1, 7);
    g.setedges2(0, 2, 1);
    g.setedges2(0, 3, 2);
    g.setedges2(1, 2, 3);
    g.setedges2(1, 3, 5);
    g.setedges2(1, 4, 1);
    g.setedges2(3, 4, 7);

    g.showlist();

    // stack<int> topo;
    // unordered_map<int, bool> visited;

    // for (int i = 0; i < 6; i++)
    // {
    //     if (!visited[i])
    //     {
    //         g.topologicalsort(visited, i, topo);
    //     }
    // }

    vector<int> dis(5);
    for (int i = 0; i < 5; i++)
    {
        dis[i] = INT_MAX;
    }

    int src = 1;

    cout << endl;

    // g.get_shortest_path(src, topo, dis);
    g.dijkstra_algo(0, dis);

    for (int i = 0; i < 5; i++)
    {
        if (dis[i] == INT_MAX)
        {
            cout << "INF ";
        }
        else
        {
            cout << dis[i] << " ";
        }
    }

    cout << endl
         << endl
         << "Articulation\n";

    vector<vector<int>> edges;
    edges = {{0, 3}, {0, 1}, {0, 4}, {1, 2}, {3, 4}};
    vector<int> ans = articulation(edges, 5, 5);
    for (auto a : ans)
    {
        cout << a << " ";
    }

    return 0;
}