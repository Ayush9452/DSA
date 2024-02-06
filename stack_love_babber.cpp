#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

/*
class Stack
{
    // prooerties
public:
    int top, siz;
    int *arr;

    // behavior
    Stack(int n)
    {
        this->top = -1;
        this->siz = n;
        this->arr = new int[n];
    }

    int size()
    {
        return (this->top + 1);
    }

    int capacity()
    {
        return this->siz;
    }

    bool full()
    {
        if (this->top == this->siz - 1)
        {
            return 1;
        }
        return 0;
    }

    void push(int val)
    {
        if (this->top == this->siz - 1)
        {
            cout << "STACK OVERFLOW \n";
            return;
        }
        this->top++;
        arr[this->top] = val;
        return;
    }

    bool empty()
    {
        if (this->top == -1)
        {
            return 1;
        }
        return 0;
    }

    int pop()
    {
        if (this->empty())
        {
            cout << "STACK UNDERFLOW ";
            return -1;
        }
        int val = this->arr[this->top];
        this->top--;
        return val;
    }

    int peek()
    {
        if (this->empty())
        {
            cout << "STACK UNDERFLOW ";
            return -1;
        }
        return this->arr[this->top];
    }

    int at(int pos)
    {
        if (pos >= 0 && pos <= this->top)
        {
            return this->arr[pos];
        }
        else
        {
            cout << "INVALID INPUT ";
        }
        return -1;
    }
};

// datastructure using single array of size s for two stack
class TwoStack
{

public:
    int top1, top2, size;
    int *arr;

    TwoStack(int s)
    {
        // stack 1 starts from left
        // stack 2 starts from right
        arr = new int[size];
        this->top1 = -1;
        this->top2 = s;
        this->size = s;
    }

    void push1(int num)
    {

        if (this->top2 - this->top1 > 1)
        {
            this->top1++;
            this->arr[this->top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        if (this->top2 - this->top1 > 1)
        {
            this->top2--;
            this->arr[this->top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if (this->top1 >= 0)
        {
            int val = this->arr[this->top1];
            this->top1--;
            return val;
        }
        else
            return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        if (this->top2 < this->size)
        {
            int val = this->arr[this->top2];
            this->top2++;
            return val;
        }
        else
            return -1;
    }
};*/

// reverse a string using stack
string reverse_string(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }
    string ans = "";
    while (!s.empty())
    {
        char c = s.top();
        ans.push_back(c);
        s.pop();
    }
    return ans;
}

// delete middle element in a stack
void delete_middle_element(stack<int> &s, int n)
{
    // no of iterations
    int x = n / 2; // n = s.size() - 1
    // to store poped element
    int a[x];
    // storing and poping the elements
    for (int i = 0; i < x; i++)
    {
        a[i] = s.top();
        s.pop();
    }
    // deleting middle element
    s.pop();
    // refiling popd elements
    for (int i = x - 1; i >= 0; i--)
    {
        s.push(a[i]);
    }
    return;
}

// delete middle element in a stack using recursion

void solve(stack<int> &s, int count, int n)
{
    if (count == n / 2)
    {
        s.pop();
        return;
    }

    int val = s.top();
    s.pop();
    solve(s, count + 1, n);
    s.push(val);
    return;
}

void delete_middle_element2(stack<int> &s, int n)
{
    solve(s, 0, n);
}

// valid parenthesis

bool check(char s, char c)
{
    if (s == ')' && c == '(')
    {
        return 1;
    }
    if (s == '}' && c == '{')
    {
        return 1;
    }
    if (s == ']' && c == '[')
    {
        return 1;
    }
    return 0;
}

bool valid_parenthesis(string s)
{
    stack<char> p;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            p.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (p.empty())
            {
                return 0;
            }
            char c = p.top();
            if (!check(s[i], c))
            {
                return 0;
            }
            p.pop();
        }
    }

    if (p.empty())
    {
        return 1;
    }

    return 0;
}

// insert an integer at the bottom of the stack

stack<int> solve2(stack<int> s, int count, int size, int n)
{
    if (count == size)
    {
        s.push(n);
        return s;
    }
    int val = s.top();
    s.pop();
    solve2(s, count + 1, size, n);
    s.push(val);
    return s;
}

stack<int> insert_At_the_bottom(stack<int> s, int n)
{
    return solve2(s, 0, s.size(), n);
}

// reverse a stack using array

void reverse_A_stack(stack<int> &s)
{
    int n = s.size();
    if (n == 1 || n == 0)
    {
        return;
    }
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = s.top();
        s.pop();
    }
    for (int i = 0; i < n; i++)
    {
        s.push(arr[i]);
    }
    return;
}

// reverse a stack using recursion

void insert_At_the_bottom_2(stack<int> &s, int n)
{
    if (s.empty())
    {
        s.push(n);
        return;
    }
    int val = s.top();
    s.pop();
    insert_At_the_bottom_2(s, n);
    s.push(val);
    return;
}

void reverse_A_stack_Recursion(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int v = s.top();
    s.pop();
    reverse_A_stack_Recursion(s);
    insert_At_the_bottom_2(s, v);
    return;
}

// sort a stack using recursion

void insert_at_right_place(stack<int> &s, int n)
{
    if (s.empty())
    {
        s.push(n);
        return;
    }

    int c = s.top();

    if (c <= n)
    {
        s.push(n);
        return;
    }
    s.pop();
    insert_at_right_place(s, n);
    s.push(c);
}

void sort_stack(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }
    int v = s.top();
    s.pop();
    sort_stack(s);
    insert_at_right_place(s, v);
}

// redundant brackets (useless brackets e.g., "(c)" )

bool redundant_bracket(string s)
{
    stack<char> c;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            c.push(s[i]);
        }
        else if (s[i] == ')')
        {
            bool ans = 1;
            while (c.top() != '(')
            {
                ans = 0;
                c.pop();
            }
            if (ans)
            {
                return 1;
            }
            c.pop();
        }
    }
    return 0;
}

// minimum cost to make a bracket balanced i.e., }}}}}{ to convert this into a balanced bracket string

int min_cost(string s)
{
    if (s.length() & 1)
    {
        return -1;
    }
    int a = 0, b = 0;
    stack<int> c;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
        {
            a++;
            c.push(s[i]);
        }
        else
        {
            b++;
            if (!c.empty())
            {
                c.pop();
                a--;
                b--;
            }
        }
    }
    int ans = ((a + 1) / 2) + ((b + 1) / 2);
    return ans;
}

// smallest element in upcoming part of the array

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}

//  Largest Rectangle in Histogram
vector<int> smaller_prev_index(vector<int> v, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && v[s.top()] >= v[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> smaller_up_index(vector<int> v, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() != -1 && v[s.top()] >= v[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int Largest_Rectangular_area_in_Histogram(vector<int> &v, int n)
{
    int ans = INT32_MIN;
    vector<int> prev(n), up(n);
    prev = smaller_prev_index(v, n);
    up = smaller_up_index(v, n);
    for (int i = 0; i < n; i++)
    {
        if (up[i] == -1)
        {
            up[i] = n;
        }
        int b = up[i] - prev[i] - 1;
        ans = max(ans, b * v[i]);
    }
    return ans;
}

// The Celebrity Problem
int celebrity(vector<vector<int>> &v, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (v[a][b] == 1)
        {
            s.push(b);
        }
        else if (v[b][a] == 1)
        {
            s.push(a);
        }
    }
    int x = s.top();
    s.pop();
    for (int i = 0; i < n; i++)
    {
        if (v[x][i] == 1)
        {
            return -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i][x] == 0 && i != x)
        {
            return -1;
        }
    }
    return x;
}

// Max Rectangle in Binary Matrix with all 1's

/*------VERY IMPORTANT------*/

int max_area_in_A_binary_matrix(vector<vector<int>> &v, int n, int m)
{
    // n = height;
    // m = base;
    vector<int> temp(v[0]);
    int ans = Largest_Rectangular_area_in_Histogram(temp, m);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp[j] = v[0][j] + v[i][j];
            if (v[i][j] == 0)
            {
                temp[j] = 0;
            }
        }
        ans = max(ans, Largest_Rectangular_area_in_Histogram(temp, m));
    }
    return ans;
}

// /N-stack ( IMPORTANT )
class NStack
{
    int *data;
    int *next;
    int *top;
    int free_space;
    int size, stacks;
    
public:
    // Initialize your data structure.
    NStack(int s, int n)
    {
        size = n;
        stacks = s;
        data = new int[n];
        next = new int[n];
        // next intialization
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        // last next case
        next[n - 1] = -1;

        top = new int[s];
        // top intialization
        for (int i = 0; i < s; i++)
        {
            top[i] = -1;
        }
        free_space = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int n, int s)
    {
        if (free_space == -1)
        {
            return 0;
        }
        // set index
        int index = free_space;

        // update free space
        free_space = next[index];

        // set data in at the top in the stack
        data[index] = n;

        // set next prev top
        next[index] = top[s - 1];

        // update top
        top[s - 1] = index;

        return 1;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int s)
    {
        if (top[s - 1] == -1)
        {
            return -1;
        }
        int index = top[s - 1];

        // updtae top
        top[s - 1] = next[index];

        // get value
        int val = data[index];

        // set next index equal to free spot
        next[index] = free_space;

        // updtae free space
        free_space = index;

        // return val
        return val;
    }
};

// Design a stack that supports getMin() in O(1) time and O(1) extra space
class stack_find_min
{
    int *data;
    int top1;
    int size;
    int mn;

public:
    stack_find_min(int n)
    {
        size = n;
        data = new int[size];
        top1 = -1;
    }

    bool isempty()
    {
        if (top1 == -1)
        {
            return 1;
        }
        return 0;
    }

    void push(int n)
    {
        if (isempty())
        {
            top1++;
            data[top1] = n;
            mn = n;
        }
        else
        {
            if (n < mn)
            {
                top1++;
                int val = (2 * n) - mn; // formula
                data[top1] = val;
                mn = n;
            }
            else
            {
                top1++;
                data[top1] = n;
            }
        }
    }

    int top()
    {
        if (top1 == -1)
        {
            return -1;
        }

        int val = data[top1];

        if(val < mn)
        {
            return mn;
        }

        return val;
    }

    int pop()
    {
        if (top1 == -1)
        {
            return -1;
        }
        int val = data[top1];
        if (val < mn)
        {
            int val2 = (2 * mn) - val; // formula
            mn = val2;
            val = mn;
        }
        top1--;
        return val;
    }

    int getMin()
    {
        if (top1 == -1)
        {
            return -1;
        }
        return mn;
    }
};

// stack using queue << VERY IMPORTANT >>
class stack_using_queue
{
public:
    queue<int> q1;
    queue<int> q2;

    void push(int n)
    {
        if (q1.empty())
        {
            q1.push(n);
            return;
        }
        q2.push(n);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        if (q1.empty())
        {
            return -1;
        }
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        int val = q1.front();
        return val;
    }
};

void print(stack_using_queue q)
{
    while (!q.q1.empty())
    {
        cout << q.q1.front() << endl;
        q.q1.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(1); // 0
    s.push(2); // 1
    s.push(3); // 2
    s.push(4); // 3
    s.push(5); // 4
    s.push(6); // 5
    // vector<int> v = {3, 5, 3};
    // cout << Largest_Rectangular_area_in_Histogram(v, 3);
    // reverse_A_stack_Recursion(s);
    // cout<<s.top();
    return 1;
}