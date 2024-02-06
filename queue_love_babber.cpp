#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

/*
// single queue << IMPLIMENTATION >>
class que
{
    int *data;
    int front, rear;
    int size;

public:
    que(int s)
    {
        size = s;
        data = new int[size];
        front = 0;
        rear = 0;
    }

    bool IsEmpty()
    {
        if (rear == front)
        {
            rear = 0;
            front = 0;
            return 1;
        }
        return 0;
    }

    bool isFull()
    {
        if (rear == size - 1)
        {
            return 1;
        }
        return 0;
    }

    void enque(int n)
    {
        if (!isFull())
        {
            data[rear] = n;
            rear++;
        }
        else
        {
            cout << "que is full\n";
        }
    }

    int deque()
    {
        if (!IsEmpty())
        {
            int val = data[front];
            data[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return val;
        }
        return -1;
    }

    int AtFront()
    {
        if (!IsEmpty())
        {
            return data[front];
        }
        return -1;
    }
};
*/

/*
// circular queue << IMPORTANT >>

class circular_queue
{
    int *data;
    int front, rare, size;

public:
    circular_queue(int n)
    {
        size = n;
        data = new int[size];
        front = -1;
        rare = -1;
    }

    bool isFull()
    {
        if (front == (rare + 1) % size)
        {
            return 1;
        }
        return 0;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return 1;
        }
        return 0;
    }

    bool enque(int n)
    {
        if (isFull())
        {
            return 0;
        }
        else if (front == -1)
        {
            rare = 0;
            front = 0;
            data[rare] = n;
        }
        else if (rare == size - 1 && front != 0)
        {
            rare = 0;
            data[rare] = n;
        }
        else
        {
            rare++;
            data[rare] = n;
        }
        return 1;
    }

    int deque()
    {
        if (isEmpty())
        {
            return -1;
        }
        else if (front == rare)
        {
            int val = data[front];
            rare = front = -1;
            return val;
        }
        else
        {
            int val = data[front];
            front = (front + 1) % size;
            return val;
        }
    }
};
*/

/*
// doubly ended que

class deque
{
    int *data;
    int front, rear, size;

public:
    deque(int n)
    {
        size = n;
        data = new int[size];
        front = rear = -1;
    }

    bool push_front(int n)
    {
        if (isFull())
        {
            return 0;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        data[front] = n;
        return 1;
    }

    bool push_rear(int n)
    {
        if (isFull())
        {
            return 0;
        }
        else if (front == -1)
        {
            rear = front = 0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        data[rear] = n;
        return 1;
    }

    int pop_front()
    {
        if (isEmpty())
        {
            return -1;
        }
        else if (front == rear)
        {
            int val = data[front];
            rear = front = -1;
            return val;
        }
        else
        {
            int val = data[front];
            front = (front + 1) % size;
            return val;
        }
    }

    int pop_rear()
    {
        if (isEmpty())
        {
            return -1;
        }
        else if (rear == front)
        {
            int val = data[rear];
            rear = front = -1;
            return val;
        }
        else if (rear == 0)
        {
            int val = data[rear];
            rear = size - 1;
            return val;
        }
        else
        {
            int val = data[rear];
            rear--;
            return val;
        }
    }

    bool isFull()
    {
        if (rear > front)
        {
            if (rear == size - 1 && front == 0)
            {
                return 1;
            }
        }
        else
        {
            if (front == (rear + 1) % size)
            {
                return 1;
            }
        }
        return 0;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return 1;
        }
        return 0;
    }

    int getRear()
    {
        if (front == -1)
        {
            return -1;
        }
        return data[rear];
    }

    int getFront()
    {
        if (front == -1)
        {
            return -1;
        }
        return data[front];
    }
};
*/
// reverse queue using stack
queue<int> reverse(queue<int> q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    return q;
}

// reverse queue using recursion
void reverse_recursion(queue<int> q)
{
    if (q.size() == 0)
    {
        return;
    }
    int x = q.front();
    q.pop();
    reverse_recursion(q);
    q.push(x);
}

// First negative integer in every window of size k   << IMPORTANT >>
vector<long long> first_negative(vector<long long> v, int n, int k)
{
    deque<long long> q;
    vector<long long> ans;

    // set queue for first windeow
    for (int i = 0; i < k; i++)
    {
        if (v[i] < 0)
        {
            q.push_back(i);
        }
    }

    // update answer for first window
    if (q.empty())
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(v[q.front()]);
    }

    // for rest of the window
    for (long long i = k; i < n; i++)
    {
        // removal
        if (i - q.front() >= k && !q.empty()) // IMPORTANT
        {
            q.pop_front();
        }
        // insertion
        if (v[i] < 0)
        {
            q.push_back(i);
        }
        // update answer
        if (q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(v[q.front()]);
        }
    }
    return ans;
}

// reverse first k elements of queue
queue<int> reverse_first_k(queue<int> &q, int k)
{
    int n = q.size();
    stack<int> s;
    // store first k elements
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    // send them in queue inn reverse order in the back of queue
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    // send the n - k element in the back of the queue
    for (int i = 0; i < n - k; i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    // return the modified queue
    return q;
}

// first non_reapting element in a string
string non_reapiting(string s)
{
    // to store charcter in line
    queue<char> q;

    // to keep the the track of repition of the charcter
    int a[26] = {0};
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        // increment the count of the string
        a[s[i] - 'a']++;

        // push in the queue
        q.push(s[i]);

        // deque the front if it is repeated until front is not repeated or until queue gets empty
        while (a[q.front() - 'a'] != 1 && !q.empty())
        {
            q.pop();
        }

        // update the answer according to queue
        if (q.empty())
        {
            ans.push_back('#');
        }
        else
        {
            ans.push_back(q.front());
        }
    }

    // return ans
    return ans;
}

// Circular tour  << IMPORTANT >>
class petrol_pump
{
public:
    int petrol_capacity;
    int distance_to_next_petrol_pump;
};

int start_point_to_complete_the_tour(petrol_pump a[], int n)
{
    int dificit = 0;
    int bal = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        bal += a[i].petrol_capacity - a[i].distance_to_next_petrol_pump;
        if (bal < 0)
        {
            dificit = bal;
            bal = 0;
            start = i + 1;
        }
    }

    if (dificit + bal >= 0)
    {
        return start;
    }
    return -1;
}

// N-queue in a array  << IMPORTANT >>
class N_queue
{
    int *data;
    int *front;
    int *rear;
    int *next;
    int size;
    int queues;
    int free_space;

public:
    N_queue(int s, int n)
    {
        size = n;
        queues = s;

        data = new int[size];
        next = new int[size];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        front = new int[queues];
        rear = new int[queues];
        for (int i = 0; i < n; i++)
        {
            front[i] = rear[i] = -1;
        }

        free_space = 0;
    }

    bool push(int n, int s)
    {
        // no space left
        if (free_space == -1)
        {
            cout << "space_khatm\n";
            return 0;
        }

        // set indexx and update freespot
        int index = free_space;
        free_space = next[index];

        // push data
        data[index] = n;

        // update front and rear
        if (front[s - 1] == -1) // first element of the queue
        {
            front[s - 1] = rear[s - 1] = index;
        }
        else // elrment of the non-empty queue
        {
            next[rear[s - 1]] = rear[s - 1] = index;
        }

        // set next[rear] = -1 to signify the end of the queue
        next[index] = -1;

        // return true for successfull pushing
        return 1;
    }

    int pop(int s)
    {
        // empty queue
        if (front[s - 1] == -1)
        {
            cout << "khali_h_bhai\n";
            return -1;
        }

        // set index
        int index = front[s - 1];

        // update front
        front[s - 1] = next[index];

        // get value of front
        int val = data[index];

        // link prev front to freespace
        next[index] = free_space;

        // free prev front
        free_space = index;

        // return front value
        return val;
    }
};

// Sum of min & max elements of all subarray of size K
int sum_of_min_and_max(vector<int> v, int n, int k)
{
    deque<int> mini(k);
    deque<int> maxi(k);

    // first window
    for (int i = 0; i < k; i++)
    {
        // addition
        while (!maxi.empty() && (v[maxi.back()] <= v[i]))
            maxi.pop_back();

        maxi.push_back(i);
        while (!mini.empty() && (v[mini.back()] >= v[i]))
            mini.pop_back();

        mini.push_back(i);
    }
    int ans = 0;

    // min + max for first window only
    ans += (v[maxi.front()] + v[mini.front()]);

    // rest of the window
    for (int i = k; i < n; i++)
    {

        // for mini
        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        // for maxi
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }

        // addition
        while (!maxi.empty() && (v[maxi.back()] <= v[i]))
            maxi.pop_back();

        maxi.push_back(i);
        while (!mini.empty() && (v[mini.back()] >= v[i]))
            mini.pop_back();

        mini.push_back(i);

        // answer update
        ans += (v[maxi.front()] + v[mini.front()]);
    }

    return ans;
}

// queue using stack << VERY IMPORTANT >>
class queue_using_stack
{
public:
    stack<int> s1;
    stack<int> s2;

    void push(int n)
    {
        if (s1.empty())
        {
            s1.push(n);
            return;
        }
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(n);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        if (s1.empty())
        {
            return -1;
        }
        int val = s1.top();
        s1.pop();
        return val;
    }

    int front()
    {
        if (s1.empty())
        {
            return -1;
        }
        int val = s1.top();
        return val;
    }
};

void print(queue_using_stack q)
{
    while (!q.s1.empty())
    {
        cout << q.s1.top() << " ";
        q.s1.pop();
    }
    NL;
}

int main()
{
    vector<int> v = {2, 5, -1, 7, -3, -1, -2};
    cout << "chal rha h\n";
    cout << sum_of_min_and_max(v, v.size(), 4) << endl;
    return 0;
}