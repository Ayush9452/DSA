#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

// level Order insertion
node *tree(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }

    if (val < root->data)
    {
        root->left = tree(root->left, val);
    }
    else
    {
        root->right = tree(root->right, val);
    }
    return root;
}

void inorder(node *a)
{
    if (a == NULL)
    {
        return;
    }
    inorder(a->left);
    cout << a->data << " ";
    inorder(a->right);
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
};

int isBST(node *root)
{
    static node *prev = NULL;
    if (root == NULL)
    {
        return 1;
    }
    else
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
}

node *ayush(node *root, int a)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == a)
    {
        return root;
    }
    else if (a > root->data)
    {
        return ayush(root->right, a);
    }
    else
    {
        return ayush(root->left, a);
    }
}

void insert_inBST(node *root, int val)
{

    node *prev = NULL;
    node *ptr = root;
    while (ptr != NULL)
    {
        prev = ptr;
        if (val == ptr->data)
        {
            cout << "ALREADY PRESENT\n";
            return;
        }
        if (val < ptr->data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    if (prev->data > val)
    {
        prev->left = new node(val);
    }
    else
    {
        prev->right = new node(val);
    }
}

node *inpred(node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

node *delet(node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    if (root->data > val)
    {
        root->left = delet(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = delet(root->right, val);
    }
    else
    {
        node *pre = inpred(root);
        root->data = pre->data;
        root->left = delet(root->left, pre->data); // because of predecessor
    }
    return root;
}

int lowest_common_ancesctor(node *root, int a, int b)
{

    if (root->data > a && root->data < b)
    {
        return root->data;
    }
    else if (root->data == a || root->data == b)
    {
        return root->data;
    }
    else
    {
        if (root->data > a && root->data > b)
        {
            return lowest_common_ancesctor(root->left, a, b);
        }
        else
        {
            return lowest_common_ancesctor(root->right, a, b);
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
        root = tree(root, data);
    }
    levelOrder(root);
    cout << endl
         << endl;
    // cout << isBST(root);
    // node *x = ayush(root, 9);
    // if (x == NULL)
    // {
    //     cout << "DATA NOT FOUND\n";
    // }
    // else
    // {
    //     cout << "FOUND : " << x->data << endl;
    // }
    // insert_inBST(root, 9);
    // cout<<root->right->right->right->data<<endl;
    root = delet(root, 4);
    // inorder(root);
    levelOrder(root);
    return 0;
}