#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// build tree
Node *build_tree(Node *root)
{
    // cout << "enter the data :- ";
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);
    // cout << "enter the data for left child of " << data << " :- ";
    root->left = build_tree(root->left);
    // cout << "enter the data for right child of " << data << " :- ";
    root->right = build_tree(root->right);
    return root;
}

// DFS
void levelOrdertraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << "\n";
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return;
}

// << IMPORTANT >>
void reverselevelOrdertraversal(Node *root)
{
    stack<Node *> s;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            s.push(NULL);
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            s.push(temp);

            if (temp->right)
            {
                q.push(temp->right);
            }

            if (temp->left)
            {
                q.push(temp->left);
            }
        }
    }

    while (!s.empty())
    {
        Node *top = s.top();
        s.pop();
        if (top == NULL)
        {
            cout << "\n";
        }
        else
        {
            cout << top->data << " ";
        }
    }
}

// InOerder Traversal  (LNR)
void inOrdertraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrdertraversal(root->left);
    cout << root->data << " ";
    inOrdertraversal(root->right);
}

// PreOrder Traversal (NLR)
void preOrdertraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrdertraversal(root->left);
    preOrdertraversal(root->right);
}

// PostOrder traversal (LRN)
void postOrdertraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrdertraversal(root->left);
    postOrdertraversal(root->right);
    cout << root->data << " ";
}

// build tree from level order traversal << IMPORTANT >>
void build_tree_levelorder(Node *&root)
{
    queue<Node *> q;
    // cout << "Enter root data :- ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // left k data
        // cout << "Enter data for left child of " << temp->data << " :- ";
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1)
        {
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        // right k data
        // cout << "Enter data for right child of " << temp->data << " :- ";
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1)
        {
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}

int count_leaf_Nodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return (count_leaf_Nodes(root->left) + count_leaf_Nodes(root->right));
}

int height_of_a_binarytree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + max(height_of_a_binarytree(root->left), height_of_a_binarytree(root->right));
}

// Diameter of a tree T(n^2) S(height)
int diameter_of_binarytree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // diameter of left sub tree i.e., if max dia is on left sub tree
    int a = diameter_of_binarytree(root->left);

    // diameter of Right sub tree i.e., if max dia is on Right sub tree
    int b = diameter_of_binarytree(root->right);

    // diameter of Root node i.e., if max dia is across Root node
    int c = height_of_a_binarytree(root->left) + height_of_a_binarytree(root->right) + 1;

    return max(a, max(b, c));
}

// Diameter of tree T(n) S(height) << IMPORTANT >>
pair<int, int> dia(Node *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }

    pair<int, int> from_left = dia(root->left);
    pair<int, int> from_right = dia(root->right);

    int a = from_left.first;
    int b = from_right.first;
    int c = from_left.second + 1 + from_right.second;

    int h = max(from_left.second, from_right.second);
    return {max(a, max(b, c)), h + 1};
}

int diameter_of_a_tree2(Node *root)
{
    pair<int, int> ans = dia(root);
    return ans.first;
}

// Balanced tree or not << VERY IMPORTANT >>
pair<bool, int> bal(Node *root)
{
    if (root == NULL)
    {
        return {1, 0};
    }

    pair<bool, int> from_left = bal(root->left);
    pair<bool, int> from_right = bal(root->right);

    bool a = from_left.first;
    bool b = from_right.first;
    bool c = (abs(from_left.second - from_right.second) <= 1);

    int h = max(from_left.second, from_right.second);

    return {((a & b) & c), h + 1};
}

bool IsBal(Node *root)
{
    return bal(root).first;
}

// TWO TREES ARE EQAU OR NOT
// usinfg stack
stack<int> inorder(Node *root, stack<int> &s)
{
    if (root == NULL)
    {
        return s;
    }
    s = inorder(root->left, s);
    s.push(root->data);
    s = inorder(root->right, s);
}

bool isEqual(Node *root1, Node *root2)
{
    if (root1->data != root2->data)
    {
        return 0;
    }
    stack<int> s1 = inorder(root1, s1);
    stack<int> s2 = inorder(root2, s2);

    while (!s1.empty() && !s2.empty())
    {
        if (s1.top() != s2.top())
        {
            return 0;
        }
        s1.pop();
        s2.pop();
    }
    if (!s1.empty() || !s2.empty())
    {
        return 0;
    }
    return 1;
}

// without stack
bool isEqual2(Node *root1, Node *root2)
{
    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
    {
        return 0;
    }

    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }

    if (root1->data != root2->data)
    {
        return 0;
    }

    bool from_left = isEqual2(root1->left, root2->left);
    bool from_right = isEqual2(root1->right, root2->right);
    return (from_left & from_right);
}

// nade value = sum of left sub tree and right sub tree (except for leaf node) << IMPORTANT >>
pair<bool, int> check(Node *root) // (true/false,sum)
{
    if (root == NULL)
    {
        return {1, 0};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data};
    }

    pair<bool, int> from_left = check(root->left);
    pair<bool, int> from_right = check(root->right);

    bool a = from_left.first;
    bool b = from_right.first;
    bool c = (from_left.second + from_right.second) == root->data;

    int sum = from_left.second + from_right.second + root->data;

    return {a & b & c, sum};
}

bool istrue(Node *root)
{
    return check(root).first;
}

// Zig_Zag traversal << VERY IMPORTANT >>
vector<int> Zig_Zag_traversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);

    bool side = 1;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        for (int i = 0; i < size; i++)
        {
            Node *frontelement = q.front();
            q.pop();

            int index = side ? i : size - i - 1;
            temp[index] = frontelement->data;

            if (frontelement->left)
            {
                q.push(frontelement->left);
            }
            if (frontelement->right)
            {
                q.push(frontelement->right);
            }
        }
        side = !side;
        for (auto i : temp)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

// boundary traversal << IMPORTANT >>
void left_part(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        left_part(root->left, ans);
    }
    else
    {
        left_part(root->right, ans);
    }
}

void leaf_part(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    leaf_part(root->left, ans);
    leaf_part(root->right, ans);
}

void right_part(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->right)
    {
        right_part(root->right, ans);
    }
    else
    {
        right_part(root->left, ans);
    }
    ans.push_back(root->data);
}

vector<int> boundary_traversal(Node *root)
{
    vector<int> ans;
    ans.push_back(root->data);
    left_part(root->left, ans);
    if (root->right || root->left)
        leaf_part(root, ans);
    right_part(root->right, ans);
    return ans;
}

// VERTICAL OREDR TRAVERSAL << VERY VERY VERY IMPORTANT >>
vector<int> VERTICAL_OREDR_TRAVERSAL(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<pair<Node *, pair<int, int>>> q; // {root,{dis,lev}}
    map<int, map<int, vector<int>>> m; // {dis,{lev,vector}}

    q.push({root, {0, 0}});

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp;
        temp = q.front();
        q.pop();

        Node *first_node = temp.first;
        int dis = temp.second.first;
        int lev = temp.second.second;

        m[dis][lev].push_back(first_node->data); // IMPORTANT LINE

        if (first_node->left)
        {
            q.push({first_node->left, {dis - 1, lev + 1}});
        }

        if (first_node->right)
        {
            q.push({first_node->right, {dis + 1, lev + 1}});
        }
    }
    for (auto i : m)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

// TOP VIEW << IMPORATANT >>
vector<int> top_view(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> m; // {dis,data}

    queue<pair<Node *, int>> q; //{root,dis}
    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *first_node = temp.first;
        int dis = temp.second;

        if (!m[dis]) // !m[dis] can also be written as (m.find(dis) == m.end())
        {
            m[dis] = first_node->data;
        }

        if (first_node->left)
        {
            q.push({first_node->left, dis - 1});
        }
        if (first_node->right)
        {
            q.push({first_node->right, dis + 1});
        }
    }

    for (auto i : m)
    {
        ans.push_back(i.second);
    }
    return ans;
}

// BOTTOM VIEW
vector<int> bottom_view(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> m; //{dis,data}
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *first_node = temp.first;
        int dis = temp.second;

        m[dis] = first_node->data;

        if (first_node->left)
        {
            q.push({first_node->left, dis - 1});
        }

        if (first_node->right)
        {
            q.push({first_node->right, dis + 1});
        }
    }
    for (auto i : m)
    {
        ans.push_back(i.second);
    }
    return ans;
}

// RIGHT VIEW
vector<int> right_view(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> m; // {level,data}
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *front_node = temp.first;
        int h = temp.second;

        m[h] = front_node->data;

        if (front_node->left)
        {
            q.push({front_node->left, h + 1});
        }

        if (front_node->right)
        {
            q.push({front_node->right, h + 1});
        }
    }

    for (auto i : m)
    {
        ans.push_back(i.second);
    }
}
// RIGHT view using recuresion << IMPORTANT >>
void call_right(Node *root, vector<int> &v, int lev)
{
    if (root == NULL)
    {
        return;
    }

    if (lev == v.size())
    {
        v.push_back(root->data);
    }

    call_right(root->right, v, lev + 1);
    call_right(root->left, v, lev + 1);
}

vector<int> right_view_2(Node *root)
{
    vector<int> ans;
    call_right(root, ans, 0);
    return ans;
}

// LEFT VIEW
vector<int> left_view(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> m; // {level,data}
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *front_node = temp.first;
        int h = temp.second;

        m[h] = front_node->data;

        if (front_node->right)
        {
            q.push({front_node->right, h + 1});
        }

        if (front_node->left)
        {
            q.push({front_node->left, h + 1});
        }
    }
    for (auto i : m)
    {
        ans.push_back(i.second);
    }
    return ans;
}
// left view usinf recuresion << IMPORTANT >>
void call_left(Node *root, vector<int> &v, int lev)
{
    if (root == NULL)
    {
        return;
    }

    if (lev == v.size())
    {
        v.push_back(root->data);
    }

    call_left(root->left, v, lev + 1);
    call_left(root->right, v, lev + 1);
}

vector<int> left_view_2(Node *root)
{
    vector<int> ans;
    call_left(root, ans, 0);
    return ans;
}

// DIAGONAL TRAVERSAL  << VERY IMPORTANT >>
vector<int> diagonal_traversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        while (temp)
        {
            ans.push_back(temp->data);

            if (temp->left)
            {
                q.push(temp->left);
            }

            temp = temp->right;
        }
    }
    return ans;
}

//  Sum of Longest BloodLine:
pair<int, int> sum_height(Node *root, int h) //{h,sum}
{
    if (root == NULL)
    {
        return {h, 0};
    }
    pair<int, int> left_sum = sum_height(root->left, h + 1);
    pair<int, int> right_sum = sum_height(root->right, h + 1);

    if (left_sum.first > right_sum.first)
    {
        return {left_sum.first, left_sum.second + root->data};
    }
    else if (left_sum.first < right_sum.first)
    {
        return {right_sum.first, right_sum.second + root->data};
    }
    else
    {
        return {right_sum.first, max(right_sum.second + root->data, left_sum.second + root->data)};
    }
}

void sum_height2(Node *root, int sum, int &maxsum, int len, int &maxlen) // apply accordingly
{
    if (root == NULL)
    {
        if (len > maxlen)
        {
            maxlen = len;
            maxsum = sum;
        }
        else if (len == maxlen)
        {
            maxsum = max(sum, maxsum);
        }
        return;
    }

    sum = sum + root->data;

    sum_height2(root->left, sum, maxsum, len + 1, maxlen);
    sum_height2(root->right, sum, maxsum, len + 1, maxlen);
}

int Sum_of_Longest_BloodLine(Node *root)
{
    return sum_height(root, 0).second;
}

// least common ancestor << IMPORTANT >>
bool check(Node *root, int a)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == a)
    {
        return 1;
    }
    bool from_left = check(root->left, a);
    bool from_right = check(root->right, a);
    return (from_left | from_right);
}

Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    /*
        << THIS CAN ALSO BE WRITTEN AS

        if ((check(root->left, n1) && check(root->right, n2)) || (check(root->left, n2) && check(root->right, n1)))
        {
            return root;
        }

        Node *left = lca(root->left, n1, n2);
        Node *right = lca(root->right, n1, n2);

        if (right == NULL && left != NULL)
        {
            return left;
        }
        if (right != NULL && left == NULL)
        {
            return right;
        }
        return NULL;
    */

    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);

    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left == NULL && right != NULL)
    {
        return right;
    }
    if (left != NULL && right == NULL)
    {
        return left;
    }
    return NULL;
}

// k sum
void process(Node *root, int &count, vector<int> path, int k)
{
    if (root == NULL)
    {
        return;
    }

    path.push_back(root->data);

    process(root->left, count, path, k);

    process(root->right, count, path, k);

    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
            break;
        }
    }
    path.pop_back();
}

int sumK(Node *root, int k)
{
    int count = 0;
    vector<int> path;
    process(root, count, path, k);
    return count;
}
// kth ancestor
void search(Node *root, int k, vector<int> path, int &ans, int node)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data == node)
    {
        if (path.size() >= k)
        {
            ans = path[path.size() - k];
        }
        return;
    }

    path.push_back(root->data);

    search(root->left, k, path, ans, node);

    search(root->right, k, path, ans, node);

    path.pop_back();
}

void search2(Node *root, int &k, int node, int &ans, bool &found) // using recursion << IMPORTANT >>
{
    if (root == NULL || found)
    {
        return;
    }

    if (root->data == node)
    {
        found = 1;
        return;
    }

    search2(root->left, k, node, ans, found);

    search2(root->right, k, node, ans, found);

    if (found)
    {
        k--;
        if (k == 0)
        {
            ans = root->data;
        }
    }
    return;
}

Node *search3(Node *root, int &k, int node) // using recursion but returnig root
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == node)
    {
        if (k == 0)
        {
            return root;
        }
        return NULL;
    }

    Node *left = search3(root->left, k, node);

    Node *right = search3(root->right, k, node);

    if ((left != NULL && right == NULL) || (left == NULL && right != NULL))
    {
        k--;
        if (k == 0)
        {
            return root;
        }
    }
    return NULL;
}

int Kthancestor(Node *root, int k, int node)
{
    int ans = -1;
    vector<int> path;
    search(root, k, path, ans, node);
    return ans;
}

// get_max_sum,if node is included then nodes having connrction with that node will be excuded    << VERY IMPORTANT >>
pair<int, int> solve2(Node *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }

    pair<int, int> curr;

    pair<int, int> left = solve2(root->left);

    pair<int, int> right = solve2(root->right);

    // include
    curr.first = root->data + left.second + right.second;

    // exclude
    curr.second = max(left.first, left.second) + max(right.first, right.second);

    return curr;
}

int getmaxsum(Node *root)
{
    pair<int, int> ans = solve2(root);
    return max(ans.first, ans.second);
}

// BUILD TREE USING INORDER AND PREORDER ARRAY  << IMPORTANT >>
int position(int in[], int ele, int n) // can be optimised using a map whilch links element top index to get the pos in O(1)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == ele)
        {
            return i;
        }
    }
    return -1;
}

Node *solve(int in[], int pre[], int &index, int instart, int inend, int size)
{
    if (index >= size || instart > inend)
    {
        return NULL;
    }

    int element = pre[index++];
    Node *head = new Node(element);
    int pos = position(in, element, size); // map can also be used same as below

    // for left child
    head->left = solve(in, pre, index, instart, pos - 1, size);

    // for right child
    head->right = solve(in, pre, index, pos + 1, inend, size);

    return head;
}

Node *build_tree_using_pre_and_in_traversal(int in[], int pre[], int n)
{
    int index = 0;
    return solve(in, pre, index, 0, n - 1, n);
}

// build a tree using post and in order traversal
Node *solve3(int post[], int in[], int &index, int instart, int inend, int n, map<int, int> &m)
{
    if (index < 0 || instart > inend)
    {
        return NULL;
    }

    int ele = post[index--];
    Node *root = new Node(ele);
    int pos = m[ele];

    // for right child
    root->right = solve3(post, in, index, pos + 1, inend, n, m);

    // for left child
    root->left = solve3(post, in, index, instart, pos - 1, n, m);

    return root;
}

Node *build_a_tree_using_posta_and_in(int post[], int in[], int n)
{
    int index = n - 1;
    map<int, int> m; // to store the poition
    for (int i = 0; i < n; i++)
    {
        m[in[i]] = i;
    }
    return solve3(post, in, index, 0, n - 1, n, m);
}

// minimum time to burn a binary tree when the target is burned first       << VERY IMPORTANT >>
Node *find_target(Node *root, int t)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == t)
    {
        return root;
    }

    Node *left = find_target(root->left, t);
    Node *right = find_target(root->right, t);

    if (left)
    {
        return left;
    }

    if (right)
    {
        return right;
    }
}

int burn_tree(Node *root, int t)
{
    map<Node *, Node *> child_to_parent;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            if (front->left)
            {
                child_to_parent[front->left] = front;
                q.push(front->left);
            }

            if (front->right)
            {
                child_to_parent[front->right] = front;
                q.push(front->right);
            }
        }
    }

    Node *target_node = find_target(root, t);
    map<Node *, bool> visited;
    int time = 0;

    queue<Node *> burn;
    burn.push(target_node);
    visited[target_node] = 1;

    while (!burn.empty())
    {
        int size = burn.size();
        bool input = 0;

        for (int i = 0; i < size; i++)
        {
            Node *front = burn.front();
            burn.pop();

            if (child_to_parent[front] != NULL && !visited[child_to_parent[front]])
            {
                burn.push(child_to_parent[front]);
                visited[child_to_parent[front]] = 1;
                input = 1;
            }

            if (front->left != NULL && !visited[front->left])
            {
                burn.push(front->left);
                visited[front->left] = 1;
                input = 1;
            }

            if (front->right != NULL && !visited[front->right])
            {
                burn.push(front->right);
                visited[front->right] = 1;
                input = 1;
            }
        }
        if (input)
        {
            time++;
        }
    }
    return time;
}
// MORRIS TRAVERSAL  << IMPORTANT >>
void mosrris(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            // find predesecor
            Node *pred = curr->left;
            while (pred->right != NULL && pred->right != curr)
            {
                pred = pred->right;
            }

            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
    cout << endl;
}

// FLATTEN A BUNERY TREE;
void flatten(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Node *temp = root;
    while (root)
    {
        if (root->left)
        {
            Node *pred = root->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            pred->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
    root = temp;
}
void flatten_using_recursion(Node *root)  // same as preOreder
{
    if (root == NULL)
    {
        return;
    }

    flatten_using_recursion(root->left);

    if (root->left)
    {
        Node *pred = root->left;
        while (pred->right)
        {
            pred = pred->right;
        }
        pred->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }

    flatten_using_recursion(root->right);
}

int main()
{
    Node *root;
    root = build_tree(root);
    // build_tree_levelorder(root);
    // levelOrdertraversal(root);
    // reverselevelOrdertraversal(root);
    inOrdertraversal(root);
    NL;
    mosrris(root);
    // preOrdertraversal(root);
    // NL;
    // postOrdertraversal(root);
    // NL;
    // cout << height_of_a_binarytree(root) << endl;
    // cout << diameter_of_binarytree(root) << endl;
    // vector<int> k = VERTICAL_OREDR_TRAVERSAL(root);
    return 0;
}