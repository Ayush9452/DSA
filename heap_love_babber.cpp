#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

class heap
{
public:
    int a[100];
    int size;

    heap()
    {
        a[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size++;
        int index = size;

        a[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (a[parent] < a[index])
            {
                swap(a[parent], a[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteheap() // indexing is 1  maxheap
    {
        if (size == 0)
        {
            cout << "NOTHING TO DELETE\n";
            return;
        }
        a[1] = a[size--];

        int index = 1;
        while (index < size)
        {
            if (size >= (2 * index) && a[index] < a[2 * index])
            {
                swap(a[index], a[2 * index]);
                index = (2 * index);
            }
            else if (size >= (2 * index) + 1 && a[index] < a[(2 * index + 1)])
            {
                swap(a[index], a[(2 * index) + 1]);
                index = (2 * index) + 1;
            }
            else
            {
                return;
            }
        }
    }

    void printheap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

// heapifi means convert the tree whose root is i into heap << VERY IMPORTANT >>
void heapify(int a[], int n, int i) // indexing is 1
{
    int largest = i;
    int left = 2 * i;
    int right = (2 * i) + 1;

    if (left < n && a[largest] < a[left])
    {
        largest = left;
    }
    if (right < n && a[largest] < a[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

// HEAP SORT O(nlogn)
// heapify for 0 indexing
void heapify(vector<int> &a, int n, int i) // max heap
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[largest] < a[left])
    {
        largest = left;
    }
    if (right < n && a[largest] < a[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

vector<int> heap_sort(vector<int> &a, int n)
{
    // convert vector to max heap
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    // sort heap
    int size = n;
    while (size > 0)
    {
        swap(a[0], a[size - 1]);
        size--;

        heapify(a, size, 0);
    }
    return a;
}

// kth smallest element
void min_heapify(vector<int> &v, int n, int i)
{
    int smallest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < n && v[left] < v[smallest])
    {
        smallest = left;
    }
    if (right < n && v[right] < v[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(v[smallest], v[i]);
        min_heapify(v, n, smallest);
    }
}

int kthsmallest(vector<int> v, int n, int k) // method 1
{
    int t = k;
    for (int i = n / 2; i >= 0; i--)
    {
        min_heapify(v, n, i);
    }
    int size = n;
    while (size > 0)
    {
        swap(v[0], v[size - 1]); // descending order
        size--;

        min_heapify(v, size, 0);
    }

    return v[v.size() - k];
}

int kth(vector<int> v, int n, int k) // method 2 << NICE METHOD >>
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(v[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (v[i] < pq.top())
        {
            pq.pop();
            pq.push(v[i]);
        }
    }
    return pq.top();
}

// if a tree is a maxheap  << IMPORTANT APPROCH >>
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

int countnode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countnode(root->left) + 1 + countnode(root->right);
}

bool iscmp(Node *root, int i, int n)
{
    if (root == NULL)
    {
        return 1;
    }

    if (i >= n)
    {
        return 0;
    }

    bool left = iscmp(root->left, (2 * i) + 1, n);
    bool right = iscmp(root->right, (2 * i) + 2, n);

    return (left & right);
}

bool ismaxheap(struct Node *root)
{
    if (root == NULL)
    {
        return 1;
    }

    if (root->left != NULL && root->data < root->left->data)
    {
        return 0;
    }

    if (root->right != NULL && root->data < root->right->data)
    {
        return 0;
    }

    bool left = ismaxheap(root->left);
    bool right = ismaxheap(root->right);

    return (left & right);
}

bool iftreeisaheap(Node *root)
{
    if (root == NULL)
    {
        return 1;
    }

    int n = countnode(root);
    bool is_complete_binary_tree = iscmp(root, 0, n);
    bool is_max_heap = ismaxheap(root);

    return (is_max_heap & is_complete_binary_tree);
}

// merge two heap
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> c(a);
    for (int i = 0; i < m; i++)
    {
        c.push_back(b[i]);
    }
    int s = n + m;
    for (int i = s / 2; i >= 0; i--)
    {
        heapify(c, s, i);
    }
    return c;
}

// Minimum Cost of ropes << GOOD USE OF MIN_HEAP >>
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

// kth largest sum of subarray  S(k)  (only space optimization is possiple)
int kth_largest_sub_array(vector<int> v, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += v[j];
            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}

//  merge k_sorted array
vector<int> merge_k_sorted_array(vector<vector<int>> &v, int k) // NORMAL METHOD
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            pq.push(v[i][j]);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

// << VERY VERY VERY VERY IMPORTANT >>
class type
{
public:
    int data;
    int i;
    int j;
};

class comp // << VERY IMPORTANT >>
{
public:
    bool operator()(type *a, type *b)
    {
        return a->data > b->data;
    }
};

vector<int> merge_k_sorted_array(vector<vector<int>> &v, int k) // << VERY IMPORTANT METHOD >>
{
    priority_queue<type *, vector<type *>, comp> pq;
    for (int i = 0; i < k; i++)
    {
        type *t = new type();
        t->data = v[i][0];
        t->i = 0;
        t->j = i;
        pq.push(t);
    }
    vector<int> ans;
    while (!pq.empty())
    {
        type *t = new type();
        t = pq.top();
        pq.pop();
        ans.push_back(t->data);
        t->i++;
        if (t->i < v[t->j].size())
        {
            t->data = v[t->j][t->i];
            pq.push(t);
        }
    }
    return ans;
}

// MERGE L SORTED LINKED LIST << SAME AS ABOVE >>
class lll // LINKED LIST NODE
{
public:
    int data;
    lll *next;
};

class type2
{
public:
    lll *a;
    int i;
};

class comp2
{
public:
    bool operator()(type2 *x, type2 *y)
    {
        return (x->a->data > y->a->data);
    }
};

lll *merge_k_sorted_linked_list(vector<lll *> &v, int k)
{
    priority_queue<type2 *, vector<type2 *>, comp2> pq;
    for (int i = 0; i < k; i++)
    {
        type2 *t = new type2();
        t->a = v[i];
        t->i = i;
        if (v[i] != NULL)
        {
            pq.push(t);
        }
    }

    lll *ans_head = NULL;
    lll *tail = NULL;

    while (!pq.empty())
    {
        type2 *n = pq.top();
        pq.pop();

        v[n->i] = v[n->i]->next;

        if (ans_head == NULL && tail == NULL)
        {
            ans_head = n->a;
            tail = n->a;
        }
        else
        {
            tail->next = n->a;
            tail = tail->next;
        }

        if (v[n->i] != NULL)
        {
            n->a = v[n->i];
            pq.push(n);
        }
    }
    return ans_head;
    //    _________________CAN ALSO BE WRITTEN AS______________________     ||
    // without using any external class
    /*class comp2
    {
    public:
        bool operator()(Node<int> *x, Node<int> *y)
        {
            return (x->data > y->data);
        }
    };

    Node<int>* mergeKLists(vector<Node<int>*> &v)
    {
        // Write your code here.
        int k = v.size();
        priority_queue<Node<int> *, vector<Node<int> *>, comp2> pq;
        for (int i = 0; i < k; i++)
        {
            if(v[i] != NULL)
            {
                pq.push(v[i]);
            }
        }

        Node<int> *ans_head = NULL;
        Node<int> *tail = NULL;

        while (!pq.empty())
        {
            Node<int> *n = pq.top();
            pq.pop();

            if (ans_head == NULL && tail == NULL)
            {
                ans_head = n;
                tail = n;
            }
            else
            {
                tail->next = n;
                tail = tail->next;
            }

            if(tail->next != NULL)
            {
                pq.push(tail->next);
            }
        }
        return ans_head;
    }*/
}

// --------------------------  HARD QUESTIONS << VERY VERY VERY IMPORTANT >> --------------------------------

// smallest range in k sorted list so that it can cover at least one element of each array
class imfo
{
public:
    int data;
    int i;
    int j;
};

class comp3
{
public:
    bool operator()(imfo *a, imfo *b)
    {
        return a->data > b->data;
    }
};

int smallest_range(vector<vector<int>> &v, int k, int n)
{
    priority_queue<imfo *, vector<imfo *>, comp3> mn;
    priority_queue<int> mx; // int mx = INT_MIN;

    for (int i = 0; i < k; i++)
    {
        imfo *t = new imfo;
        t->data = v[i][0];
        t->i = 0;
        t->j = i;
        mn.push(t);
        mx.push(v[i][0]); // mx = max(mx,v[i][0]);
    }

    int ans = INT_MAX;

    while (mn.size() >= k)
    {
        imfo *temp = mn.top();
        mn.pop();
        temp->i++;

        ans = min(ans, abs(mx.top() - temp->data) + 1); // ans = min(ans, abs(mx - temp->data) + 1);

        if (temp->i < n)
        {
            temp->data = v[temp->j][temp->i];
            mn.push(temp);
            mx.push(temp->data); // mx = max(mx,temp->data);
        }
    }
    return ans;
}

// MEDIAN IN A STREAM << VERY VERY IMPORTANT >>
// median of vector till which it has read  << USE OF HEAP IS DONE EXCELLENTELY >>
vector<int> median(vector<int> &v)
{
    int n = v.size();
    vector<int> ans;

    int median = 0;

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    for (int i = 0; i < n; i++)
    {
        int ele = v[i];
        if (left.size() == right.size())
        {
            if (ele < median)
            {
                left.push(ele);
                median = left.top();
            }
            else
            {
                right.push(ele);
                median = right.top();
            }
        }
        else if (right.size() > left.size())
        {
            if (ele < median)
            {
                left.push(ele);
            }
            else
            {
                left.push(right.top());
                right.pop();
                right.push(ele);
            }
            median = (right.top() + left.top()) / 2;
        }
        else if (right.size() < left.size())
        {
            if (ele < median)
            {
                right.push(left.top());
                left.pop();
                left.push(ele);
            }
            else
            {
                right.push(ele);
            }
            median = (right.top() + left.top()) / 2;
        }
        ans.push_back(median);
    }
    return ans;
}

// Rearrange string no adjacent char is similar
string reArrangeString(string &s)
{
    int n = s.length();

    map<char,int> m;
    for(int i = 0 ;i<n;i++)
    {
        m[s[i]]++;
    }

    priority_queue<pair<int,char>> pq;
    for(auto d:m)
    {
        pq.push({d.second,d.first});
    }
    
    string ans = "";
    pair<int,char> block = {-1,'#'};
    while(!pq.empty())
    {
        pair<int,char> temp = pq.top();
        pq.pop();
        
        ans.push_back(temp.second);
        temp.first--;
        
        if(block.first > 0)
        {
            pq.push(block);
        }
        
        block = temp;
    }

    if(ans.length() != n)
    {
        return "not possible";
    }
    return ans;
}

int main()
{
    // heap h;
    // h.insert(55);
    // h.insert(34);
    // h.insert(94);
    // h.insert(453);
    // h.insert(2);
    // h.printheap();

    // int a[6] = {-1, 55, 34, 94, 453, 2};
    // for (int i = 5 / 2; i > 0; i--)
    // {
    //     heapify(a, 5, i);
    // }
    // for (int i = 1; i <= 5; i++)
    // {
    //     cout << a[i] << " ";
    // }

    // heap using STL
    priority_queue<int> pq;                                  // default = maxheap
    priority_queue<int, vector<int>, greater<int>> min_heap; // minheap

    pq.push(3);
    pq.push(5);
    pq.pop();
    pq.top();
    pq.empty();
    pq.size();
    return 0;
}