#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    int height;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int get_height(node *a)
{
    if (a == NULL)
    {
        return 0;
    }
    return a->height;
}

int balaned_height(node *a)
{
    if (a == NULL)
    {
        return 0;
    }
    return (get_height(a->left) - get_height(a->right));
}

node *left_rotation(node *x)
{
    node *y = x->right;
    node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    return y;
}

node *right_rotation(node *y)
{
    node *x = y->left;
    node *t2 = x->right;

    x->right = y;
    y->left = t2;

    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    return x;
}

node *create_tree(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    else
    {
        node *cur;
        if (val <= root->data)
        {
            cur = create_tree(root->left, val);
            root->left = cur;
        }
        else
        {
            cur = create_tree(root->right, val);
            root->right = cur;
        }
    }

    root->height = 1 + max(get_height(root->left), get_height(root->right));

    int bf = balaned_height(root);
    // cout << bf << " " << root->data << endl;

    if (bf > 1 && val < root->left->data)
    {
        return right_rotation(root);
    }
    if (bf < -1 && val > root->right->data)
    {
        return left_rotation(root);
    }
    if (bf > 1 && val > root->left->data)
    {
        root->left = left_rotation(root->left);
        return right_rotation(root);
    }
    if (bf < -1 && val < root->right->data)
    {
        root->right = right_rotation(root->right);
        return left_rotation(root);
    }
    return root;
}

void levelOrder(node *root)
{

    if (root == NULL)
    {
        // cout << "  ";
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *Node = q.front();
        q.pop();
        if (Node != NULL)
        {
            cout << Node->data << " ";
            if (Node->left)
            {
                q.push(Node->left);
            }
            if (Node->right)
            {
                q.push(Node->right);
            }
        }
        else
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
            }
        }
    }
}

int main()
{
    node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        root = create_tree(root, data);
    }
    root = create_tree(root, 5);
    levelOrder(root);
    return 0;
}