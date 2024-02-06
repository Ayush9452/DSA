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
    Node *right;
    Node *left;

    Node(int val)
    {
        this->data = val;
        this->right = NULL;
        this->left = NULL;
    }
};

Node *build_BST(Node *root, int val)
{
    if (root == NULL)
    {
        Node *node = new Node(val);
        return node;
    }

    if (val < root->data)
    {
        root->left = build_BST(root->left, val);
    }
    else
    {
        root->right = build_BST(root->right, val);
    }
}

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

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int min_val(Node *root)
{
    if (root->left == NULL)
    {
        return root->data;
    }
    return min_val(root->left);
}

int max_val(Node *root)
{
    if (root->right == NULL)
    {
        return root->data;
    }
    return max_val(root->right);
}

// << VERY IMPORTANT >>
void morrish_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Node *temp = root;

    while (temp)
    {
        if (temp->left == NULL)
        {
            cout << temp->data << " ";
            temp = temp->right;
        }
        else
        {
            Node *pred = temp->left;

            while (pred->right != NULL && pred->right != temp)
            {
                pred = pred->right;
            }

            if (pred->right == NULL)
            {
                pred->right = temp;
                temp = temp->left;
            }
            else
            {
                pred->right = NULL;
                cout << temp->data << " ";
                temp = temp->right;
            }
        }
    }
}

void reverse_morris(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Node *curr = root;
    while (curr)
    {
        if (curr->right == NULL)
        {
            cout << curr->data << " ";
            curr = curr->left;
        }
        else
        {
            Node *pred = curr->right;

            while (pred->left != NULL && pred->left != curr)
            {
                pred = pred->left;
            }

            if (pred->left == NULL)
            {
                pred->left = curr;
                curr = curr->right;
            }
            else
            {
                pred->left = NULL;
                cout << curr->data << ' ';
                curr = curr->left;
            }
        }
    }
}

// inorder succerssor  << IMPORTANT >>
void inOrder_succ(Node *root, Node *&succ, int x)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data > x)
    {
        succ = root;
        inOrder_succ(root->left, succ, x);
    }
    else
    {
        inOrder_succ(root->right, succ, x);
    }
}

// inorder predecessor  << IMPORTANT >>
void inOrder_pred(Node *root, Node *&pred, int x)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data < x)
    {
        pred = root;
        inOrder_pred(root->right, pred, x);
    }
    else
    {
        inOrder_pred(root->left, pred, x);
    }
}

// Delete form BST  << VERY IMPORTANT >>
void min_from_right(Node *root, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    ans = root->data;
    min_from_right(root->left, ans);
}

Node *delete_node(Node *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == x)
    {
        // if root has no child
        if (root->left == NULL && root->right == NULL)
        {
            delete (root);
            return NULL;
        }
        // if left child exist
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete (root);
            return temp;
        }
        // if right child exist
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete (root);
            return temp;
        }
        // if both child exist
        else
        {
            int new_data = root->right->data;
            min_from_right(root->right, new_data);
            root->data = new_data;
            root->right = delete_node(root->right, new_data);
        }
    }
    else if (root->data > x)
    {
        root->left = delete_node(root->left, x);
    }
    else
    {
        root->right = delete_node(root->right, x);
    }

    return root;
}

// VALIDATE BST (partial binary tree)
bool validate_BST(Node *root)
{
    if (root == NULL)
    {
        return 1;
    }

    if (root->left != NULL && root->data < root->left->data)
    {
        return 0;
    }
    if (root->right != NULL && root->data >= root->right->data)
    {
        return 0;
    }

    bool from_left = validate_BST(root->left);
    bool from_right = validate_BST(root->right);

    return (from_right & from_left);
}

// kth_smallest element

void morris_kth_smallest(Node *root, int &k, int &ans)
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
            k--;
            if (k == 0)
            {
                ans = curr->data;
            }
            curr = curr->right;
        }
        else
        {
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
                k--;
                if (k == 0)
                {
                    ans = curr->data;
                }
                curr = curr->right;
            }
        }
    }
}

void inOrder_call(Node *root, int &k, int &ans)
{
    if (root == NULL)
    {
        return;
    }

    inOrder_call(root->left, k, ans);

    k--;
    if (k == 0)
    {
        ans = root->data;
    }

    inOrder_call(root->right, k, ans);
}
int kth_smallest_ele(Node *root, int k) // can be done by : Morris traversal,recursion as inorder,store inorder
{
    int ans = -1;
    inOrder_call(root, k, ans);
    return ans;
}

// least common ancestor << IMPORTANT >>
void LCA(Node *root, int a, int b, Node *&ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data > a && root->data > b)
    {
        LCA(root->left, a, b, ans);
    }
    else if (root->data < a && root->data < b)
    {
        LCA(root->right, a, b, ans);
    }
    else
    {
        ans = root;
        return;
    }
}

// find if there exist two node whose sum is equal to target
void inorder_storer(Node *root, vector<int> &a)
{
    if (root == NULL)
    {
        return;
    }
    inorder_storer(root->left, a);
    a.push_back(root->data);
    inorder_storer(root->right, a);
}

bool ifsumexist(Node *root, int t)
{
    vector<int> sorted;
    inorder_storer(root, sorted);
    int i = 0, j = sorted.size() - 1;
    while (i < j)
    {
        int sum = sorted[i] + sorted[j];
        if (sum < t)
        {
            i++;
        }
        else if (sum > t)
        {
            j--;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

// flatten binary tree in sorted order
Node *flatten(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    vector<int> v;
    inorder_storer(root, v);

    Node *newroot = new Node(v[0]);
    Node *curr = newroot;
    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i]);
        curr->right = temp;
        curr = curr->right;
    }

    return newroot;
}

// BST to balanced tree << IMPORTANT >>
Node *buildtree(Node *root, int start, int end, vector<int> v)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *temp = new Node(v[mid]);
    temp->left = buildtree(temp->left, start, mid - 1, v);
    temp->right = buildtree(temp->right, mid + 1, end, v);

    return temp;
}
Node *BSTtoBlanaced(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    vector<int> v;
    inorder_storer(root, v);

    Node *newroot = NULL;
    newroot = buildtree(newroot, 0, v.size() - 1, v);
    return newroot;
}

// build BST only using preorder in O(n2)

Node *solve(vector<int> v, int start, int end) // khud bnaya tha 1 test case fail ho rha tha
{
    if (start > end)
    {
        return NULL;
    }
    int sep;
    int parent = v[start];
    for (int i = start + 1; i <= end; i++)
    {
        if (v[i] > parent)
        {
            sep = i;
            break;
        }
    }
    Node *root = new Node(parent);
    root->left = solve(v, start + 1, sep - 1);
    root->right = solve(v, sep, end);
}

// original method << VERY IMPORTANT >> O(n)
Node *originalsolve(vector<int> &v, int &index, int min, int max)
{
    if (index == v.size())
    {
        return NULL;
    }
    if (v[index] < min || v[index] > max)
    {
        return NULL;
    }

    int val = v[index++];
    Node *root = new Node(val);
    root->left = originalsolve(v, index, min, val);
    root->right = originalsolve(v, index, val, max);

    return root;
}

// same as above but working only using upper bound
Node *original2(vector<int> &v, int &index, int max)
{
    if (index >= v.size())
    {
        return NULL;
    }
    if (v[index] > max)
    {
        return NULL;
    }

    int val = v[index++];
    Node *root = new Node(val);
    root->left = original2(v, index, val);
    root->right = original2(v, index, max);
    return root;
}

Node *buildBSTwithpreorder(vector<int> a, int n)
{
    int index = 0;
    Node *root = NULL;
    root = originalsolve(a, index, INT_MIN, INT_MAX);
    return root;
}

// merge two BST S(N+M) O(N+M)
void merge_vector(vector<int> &v1, vector<int> &v2, vector<int> &v3)
{
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] <= v2[j])
        {
            v3.push_back(v1[i++]);
        }
        else
        {
            v3.push_back(v2[j++]);
        }
    }

    while (i < v1.size())
    {
        v3.push_back(v1[i++]);
    }

    while (j < v2.size())
    {
        v3.push_back(v2[j++]);
    }
}

Node *merge(Node *root1, Node *root2) // basic method
{
    if (root1 == NULL)
    {
        return root2;
    }
    if (root2 == NULL)
    {
        return root1;
    }

    vector<int> in1;
    inorder_storer(root1, in1);
    vector<int> in2;
    inorder_storer(root2, in2);
    vector<int> merged;
    merge_vector(in1, in2, merged);

    Node *newroot;
    newroot = buildtree(newroot, 0, merged.size() - 1, merged);
    return newroot;
}

// << VERY VERY VERY IMPORTANT >>
// merge two BST s(Height)
// convert tree into doubly linked list
void treetoDLL(Node *root, Node *&head)
{
    if (root == NULL)
    {
        return;
    }

    treetoDLL(root->right, head);

    root->right = head;

    if (head != NULL)
        head->left = root;

    head = root;

    treetoDLL(root->left, head);
}

Node *mergetosortedlist(Node *root1, Node *root2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (root1 != NULL && root2 != NULL)
    {
        if (root1->data < root2->data)
        {
            if (head == NULL)
            {
                head = root1;
                tail = root1;
                root1 = root1->right;
            }
            else
            {
                tail->right = root1;
                root1->left = tail;
                tail = root1;
                root1 = root1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = root2;
                tail = root2;
                root2 = root2->right;
            }
            else
            {
                tail->right = root2;
                root2->left = tail;
                tail = root2;
                root2 = root2->right;
            }
        }
    }

    while (root1)
    {
        tail->right = root1;
        root1->left = tail;
        tail = root1;
        root1 = root1->right;
    }

    while (root2)
    {
        tail->right = root2;
        root2->left = tail;
        tail = root2;
        root2 = root2->right;
    }

    return head;
}

int countnode(Node *root)
{
    int c = 0;
    Node *temp = root;
    while (temp != NULL)
    {
        c++;
        temp = temp->right;
    }
    return c;
}

// convert sorted doubly linked list to BST
Node *DDLtoBST(Node *&root, int n)
{
    if (n <= 0 || root == NULL)
    {
        return NULL;
    }

    Node *left = DDLtoBST(root, n / 2);

    Node *midd = root;
    cout << midd->data << " " << n << endl;
    midd->left = left;
    root = root->right;

    midd->right = DDLtoBST(root, n - (n / 2) - 1);

    return midd;
}

Node *merge2(Node *root1, Node *root2)
{
    Node *head1 = NULL;
    treetoDLL(root1, head1);

    Node *head2 = NULL;
    treetoDLL(root2, head2);

    Node *head = mergetosortedlist(head1, head2);

    return DDLtoBST(head, countnode(head));
}

// largest BST in a binary tree << VERY VERY VERY VERY IMPORTANT >>
class info // GOOD USE OF CLASS
{
public:
    int size;
    int min;
    int max;
    bool isbst;
};

info solve9(Node *root, int &ans)
{
    if (root == NULL)
    {
        return {0, INT_MAX, INT_MIN, 1};
    }

    info left = solve9(root->left, ans);
    info right = solve9(root->right, ans);

    info curr;
    curr.size = left.size + right.size + 1;
    curr.max = max(root->data, right.max);
    curr.min = min(root->data, left.min);

    if (left.isbst & right.isbst)
    {
        curr.isbst = 1;
    }
    else
    {
        curr.isbst = 0;
    }

    if (curr.isbst)
    {
        ans = max(ans, curr.size);
    }
    return curr;
}

int largetBST(Node *root)
{
    int ans = 0;
    info temp = solve9(root, ans);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        root = build_BST(root, data);
    }
    levelOrdertraversal(root);
    NL;
    int n1;
    cin >> n1;
    Node *root1 = NULL;
    for (int i = 0; i < n1; i++)
    {
        int data;
        cin >> data;
        root1 = build_BST(root1, data);
    }
    levelOrdertraversal(root1);
    NL;

    Node *root3 = merge2(root, root1);
    NL;
    levelOrdertraversal(root3);
    return 0;
}