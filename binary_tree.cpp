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
        left = NULL;
        right = NULL;
    }
};

node *create_node(int val)
{
    node *n;
    n = (node *)malloc(sizeof(node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void push_left(node *a, int val)
{
    node *n = create_node(val);
    a->left = n;
}

void push_right(node *a, int val)
{
    node *n = create_node(val);
    a->right = n;
}

void preOrder_traversal(node *a)
{
    if (a == NULL)
    {
        return;
    }
    cout << a->data << " ";
    preOrder_traversal(a->left);
    preOrder_traversal(a->right);
}

void postOrder_traversal(node *a)
{
    if (a == NULL)
    {
        return;
    }
    postOrder_traversal(a->left);
    postOrder_traversal(a->right);
    cout << a->data << " ";
}

void inOrder_traversal(node *a)
{
    if (a == NULL)
    {
        return;
    }
    inOrder_traversal(a->left);
    cout << a->data << " ";
    inOrder_traversal(a->right);
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int x = height(root->left);
    int y = height(root->right);
    return max(x, y) + 1;
}

int max_number_of_edge(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int x = max_number_of_edge(root->left);
    int y = max_number_of_edge(root->right);
    return max(x, y) + 1;
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
        return root;
    }
}

void levelOrder(node *root)
{

    if (root == NULL)
    {
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
                q.push(NULL);
            }
        }
    }
};

int main()
{
    node *p = new node(4);
    node *p1 = new node(1);
    node *p2 = new node(6);
    node *p3 = new node(5);
    node *p4 = new node(2);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    //             4
    //            / \
    //           1   6
    //          / \
    //         5   2

    // cout << "PREORDER TRAVERSAL : ";
    // preOrder_traversal(p);
    // cout << endl;
    // cout << "POSTORDER TRAVERSAL : ";
    // postOrder_traversal(p);
    // cout << endl;
    // cout << "INORDER TRAVERSAL : ";
    // inOrder_traversal(p);
    // cout << endl;
    levelOrder(p);
    return 0;
}