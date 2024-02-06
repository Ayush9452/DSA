#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void print_list(node *a)
{
    while (a != NULL)
    {
        cout << a->data << " ";
        a = a->next;
    }
    cout << "\n";
}

node *insert_in_the_start(node *a, int b)
{
    node *x = (node *)malloc(sizeof(node));
    x->data = b;
    x->next = a;
    return x;
}

node *insert_at_position(node *a, int j, int b)
{
    node *p;
    p = a;
    for (int i = 1; i < j; i++)
    {
        p = p->next;
    }
    node *x = (node *)malloc(sizeof(node));
    x->data = b;
    x->next = p->next;
    p->next = x;
    return a;
}

node *insert_at_the_end(node *a, int b)
{
    node *n = new node(b);
    if (a == NULL)
    {
        return n;
    }
    node *p;
    p = a;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = n;
    n->next = NULL;
    return a;
}

void insert_at_the_end(node *&head, node *&tail, int b)
{
    node *n = new node(b);
    if (head == NULL)
    {
        tail = n;
        head = n;
        return;
    }
    tail->next = n;
    tail = n;
    return;
}

node *insert_after_node(node *a, node *c, int b)
{
    node *x = (node *)malloc(sizeof(node));
    x->data = b;
    x->next = c->next;
    c->next = x;
    return a;
}

node *delete_the_first(node *a)
{
    node *p = a;
    a = a->next;
    free(p);
    return a;
}

node *delete_at_index(node *a, int j)
{
    int i = 0;
    node *p = a;
    node *k;
    while (i != j - 1)
    {
        p = p->next;
        i++;
    }
    k = p->next;
    p->next = k->next;
    free(k);
    return a;
}

node *delete_last(node *a)
{
    node *p = a;
    node *k = p->next;
    while (k->next != NULL)
    {
        p = p->next;
        k = p->next;
    }
    p->next = NULL;
    free(k);
    return a;
}
node *delete_by_value(node *a, int b)
{
    node *p = a;
    node *k = p->next;
    while (k->data != b && k->next != NULL)
    {
        p = p->next;
        k = p->next;
    }
    if (k->data == b)
    {
        p->next = k->next;
        free(k);
    }
    else
    {
        cout << "NOT FOUND\n";
    }
    return a;
}

int compare_to_list(node *a, node *b)
{
    while (a->next != NULL && b->next != NULL)
    {
        if (a->data != b->data)
        {
            return 0;
        }
        a = a->next;
        b = b->next;
    }
    if (a->next == NULL && b->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

node *merged_sorted_list(node *a, node *b)
{
    node *n = NULL;
    while (a != NULL && b != NULL)
    {
        if (a->data <= b->data)
        {
            n = insert_at_the_end(n, a->data);
            a = a->next;
        }
        else
        {
            n = insert_at_the_end(n, b->data);
            b = b->next;
        }
    }
    while (a != NULL)
    {
        n = insert_at_the_end(n, a->data);
        a = a->next;
    }
    while (b != NULL)
    {
        n = insert_at_the_end(n, b->data);
        b = b->next;
    }
    return n;
}

// reverse using recursion
node *reverse(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *chotahead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotahead;
}

// reverse using iteration
node *reverse2(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *curr = head;
    node *prev = NULL;
    node *forward;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

node *reverse_in_k_blocks(node *&head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // reverse first k nodes
    node *prev = NULL;
    node *forward = NULL;
    node *curr = head;
    int count = 0;
    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    // recursion dekh lega aage ka
    head->next = reverse_in_k_blocks(forward, k);
    // return haed of the reversed list
    return prev;
}

// IMPORTANT

bool is_circular(node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    node *temp = head;
    while (temp != head && temp != NULL)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return 1;
    }
    return 0;
}

// IMPORTANT
bool detect_cycle(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    map<node *, bool> visited;
    node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp])
        {
            return 1;
        }
        visited[temp] = 1;
        temp = temp->next;
    }
    return 0;
}

// IMPORTANT
node *floyd_detect_cycle(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    node *slow = head;
    node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout << "cycle detected\n";
            return fast;
        }
    }
    return NULL;
}

// IMPORTANT
node *begnning_of_loop(node *head)
{
    if (head == NULL)
    {
        return head;
    }

    node *intersection = floyd_detect_cycle(head);
    node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// IMPORTANT
void remove_loop(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *starting_node = begnning_of_loop(head);
    node *temp = starting_node->next;
    while (temp->next != starting_node)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return;
}
// delete duplicates in a sorted linked list
node *del(node *curr)
{
    node *p = curr->next;
    curr->next = curr->next->next;
    free(p);
    return curr;
}

node *revised(node *head)
{
    node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            curr = del(curr);
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

// sort a linkd list of 0s,1s and 2s

node *add(node *tail, node *ptr)
{
    tail->next = ptr;
    tail = ptr;
    return tail;
}

node *sort_for_012(node *head)
{
    if (head == NULL)
    {
        return head;
    }

    node *c1 = new node(-1), *c0 = new node(-1), *c2 = new node(-1);
    node *c0_tail = c0;
    node *c1_tail = c1;
    node *c2_tail = c2;
    node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == 0)
        {
            c0_tail = add(c0_tail, ptr);
        }
        else if (ptr->data == 1)
        {
            c1_tail = add(c1_tail, ptr);
        }
        else if (ptr->data == 2)
        {
            c2_tail = add(c2_tail, ptr);
        }
    }
    if (c1->next == NULL)
    {
        c0_tail->next = c2->next;
    }
    else
    {
        c0_tail->next = c1->next;
    }
    c1_tail->next = c2->next;
    c2_tail->next = NULL;
    return c0->next;
}

// merge two sorted linked list

node *solve(node *head1, node *head2)
{
    // when list 1 have single node
    if (head1->next == NULL)
    {
        head1->next = head2;
        return head1;
    }

    node *curr, *prev, *temp;
    curr = head1->next;
    prev = head1;
    temp = head2;
    while (temp != NULL && curr != NULL)
    {
        if ((temp->data >= prev->data) && (temp->data <= curr->data))
        {
            // temp ko bich m dal denge
            node *temp2 = temp->next; // temp k age wala store kra lenge
            prev->next = temp;
            temp->next = curr;
            prev = temp;  // prev ko agew bada lenge
            temp = temp2; // temp ko fir s age wale p laga denge
        }
        else
        {
            // agea bda denge
            prev = prev->next;
            curr = curr->next;
            // ager list 1 end ho gai ho
            if (curr == NULL)
            {
                prev->next = temp;
                return head1;
            }
        }
    }
    return head1;
}

node *sortTwoLists(node *head1, node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    if (head1->data <= head2->data)
    {
        // head 1 me sare dalenge
        return solve(head1, head2);
    }
    else
    {
        // head 2 me sare dalenge
        return solve(head2, head1);
    }
}

// check if palindrm
// method 1
bool is_palindrom(node *head)
{
    node *temp = head;
    vector<int> a;
    while (temp != NULL)
    {
        a.push_back(temp->data);
        temp = temp->next;
    }
    int l = a.size();
    for (int i = 0; i <= l / 2; i++)
    {
        if (a[i] != a[l - 1 - i])
        {
            return 0;
        }
    }
    return 1;
}

// check if palindrm
// method 2
node *reverse_for_palindom(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *chotahead = reverse_for_palindom(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotahead;
}

node *getmid(node *head)
{
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool is_palindrom2(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 1;
    }
    // get middle
    node *middle = getmid(head);
    // reverse after middle
    middle->next = reverse_for_palindom(middle->next);
    // set head
    node *head1 = head;
    node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            middle->next = reverse_for_palindom(middle->next);
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    middle->next = reverse_for_palindom(middle->next);
    return 1;
}

// add 2 numbers represented by linked list using multiple loops
node *add_list(node *&head1, node *&head2)
{
    // reverse both list
    head1 = reverse(head1);
    head2 = reverse(head2);
    node *ans = NULL;
    node *tail = NULL;
    int c = 0;
    node *ptr1 = head1;
    node *ptr2 = head2;
    // until any list ends
    while (ptr1 != NULL && ptr2 != NULL)
    {
        int x = ptr1->data + ptr2->data + c;
        insert_at_the_end(ans, tail, x % 10);
        c = x / 10;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    // when list 2 is not ends though list ends
    while (ptr2 != NULL)
    {
        int x = ptr2->data + c;
        insert_at_the_end(ans, tail, x % 10);
        c = x / 10;
        ptr2 = ptr2->next;
    }
    // when list 1 is not ends though list ends
    while (ptr1 != NULL)
    {
        int x = ptr1->data + c;
        insert_at_the_end(ans, tail, x % 10);
        c = x / 10;
        ptr1 = ptr1->next;
    }
    // if carry is left
    if (c != 0)
    {
        insert_at_the_end(ans, tail, c);
    }
    // reverse both list to its original state
    head1 = reverse(head1);
    head2 = reverse(head2);
    // return reverse of ans
    return reverse(ans);
}

// add 2 numbers represented by linked list using single loop
node *add_list2(node *&head1, node *&head2)
{
    // reverse both list
    head1 = reverse(head1);
    head2 = reverse(head2);
    node *ans = NULL;
    node *tail = NULL;
    int c = 0;
    node *ptr1 = head1;
    node *ptr2 = head2;
    // until any list ends
    while (ptr1 != NULL || ptr2 != NULL || c != 0)
    {
        int val1 = 0, val2 = 0;
        if (ptr1 != NULL)
        {
            val1 = ptr1->data;
        }
        if (ptr2 != NULL)
        {
            val2 = ptr2->data;
        }
        int x = val1 + val2 + c;
        insert_at_the_end(ans, tail, x % 10);
        c = x / 10;
        if (ptr1 != NULL)
        {
            ptr1 = ptr1->next;
        }
        if (ptr2 != NULL)
        {
            ptr2 = ptr2->next;
        }
    }
    // reverse both list to its original state
    head1 = reverse(head1);
    head2 = reverse(head2);
    // return reverse of ans
    return reverse(ans);
}

node *add2_linkedlist(node *&head1, node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    // so that it can handle multiple testcases
    return add_list2(head1, head2);
}

// clone a linke dlist with random pointers
class node2
{
public:
    int data;
    node2 *next;
    node2 *ran;

    node2(int val)
    {
        this->data = val;
        this->next = NULL;
        this->ran = NULL;
    }
};

void add_end(node2 *&head, node2 *&tail, int b)
{
    node2 *n = new node2(b);
    if (head == NULL)
    {
        tail = n;
        head = n;
        return;
    }
    tail->next = n;
    tail = n;
    return;
}

node2 *copyList(node2 *head)
{
    // T = O(n) S = O(n)
    node2 *temp = NULL;
    node2 *temp_tail = NULL;
    map<node2 *, node2 *> m;
    node2 *ptr = head;
    while (ptr != NULL)
    {
        add_end(temp, temp_tail, ptr->data);
        m[ptr] = temp_tail;
        ptr = ptr->next;
    }
    ptr = head;
    node2 *ptr2 = temp;
    while (ptr != NULL)
    {
        ptr2->ran = m[ptr->ran];
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    return temp;
}

node2 *copylist_without_map(node2 *head)
{
    // T = O(n) S = O(1)
    // create a clone list
    node2 *clone_head = NULL;
    node2 *clone_tail = NULL;

    node2 *temp = head;
    while (temp != NULL)
    {
        add_end(clone_head, clone_tail, temp->data);
        temp = temp->next;
    }

    // adding lists
    node2 *original_node = head;
    node2 *clone_node = clone_head;

    while (original_node != NULL && clone_node != NULL)
    {
        node2 *next = original_node->next;
        original_node->next = clone_node;
        original_node = next;

        next = clone_node->next;
        clone_node->next = original_node;
        clone_node = next;
    }

    // arranging random pointers
    temp = head;
    while (temp != NULL)
    {
        temp->next->ran = temp->ran ? temp->ran->next : NULL; // if original->ran = NULL then clone->ran = NULL else original->ran = clone->ran
        temp = temp->next->next;
    }

    // reverting both lists
    original_node = head;
    clone_node = clone_head;

    while (original_node != NULL && clone_node != NULL)
    {
        original_node->next = clone_node->next;
        original_node = original_node->next;

        if (original_node != NULL)
        {
            clone_node->next = original_node->next;
        }
        clone_node = clone_node->next;
    }

    // return ans
    return clone_head;
}

// merge sort
node *merge_list(node *left, node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    node *ans = new node(-1);
    node *temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    return ans->next;
}

node *merge_sort(node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // create two list
    node *middle = getmid(head);
    node *left = head;
    node *right = middle->next;
    middle->next = NULL;

    // sort both lists
    left = merge_sort(left);
    right = merge_sort(right);

    // merge both list
    node *ans = merge_list(left, right);
    return ans;
}


// flatten a list
class node3
{
public:
    int data;
    node3 *next;
    node3 *child;

    node3(int d)
    {
        this->data = d;
        this->next = NULL;
        this->child = NULL;
    }
};

node3 *merge_list(node3 *down, node3 *right)
{
    node3 *head = NULL;
    node3 *tail = NULL;
    if (down->data <= right->data)
    {
        head = down;
        tail = down;
        down = down->child;
        tail->child = NULL;
    }
    else
    {
        head = right;
        tail = right;
        right = right->child;
        tail->child = NULL;
    }
    while (down != NULL && right != NULL)
    {
        if (down->data <= right->data)
        {
            tail->child = down;
            tail = down;
            down = down->child;
            tail->child = NULL;
        }
        else
        {
            tail->child = right;
            tail = right;
            right = right->child;
            tail->child = NULL;
        }
    }
    if (down)
    {
        tail->child = down;
    }
    if (right)
    {
        tail->child = right;
    }
    return head;
}

node3 *flatten_list(node3 *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node3 *down = head;
    node3 *right = flatten_list(head->next);
    head->next = NULL;
    node3 *ans = merge_list(down, right);
    return ans;
}

int main()
{
    int n1;
    cin >> n1;
    node *head1 = NULL;
    fr(i, n1)
    {
        int x;
        cin >> x;
        head1 = insert_at_the_end(head1, x);
    }
    int n2;
    cin >> n2;
    node *head2 = NULL;
    fr(i, n2)
    {
        int x;
        cin >> x;
        head2 = insert_at_the_end(head2, x);
    }
    print_list(head1);
    print_list(head2);
    print_list(add2_linkedlist(head1, head2));
    return 0;
}
