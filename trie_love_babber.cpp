#include <bits/stdc++.h>
#define ll long long
#define NL cout << endl;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

class trieNode
{
public:
    char data;
    trieNode *children[26];
    bool isterminal;

    trieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        this->isterminal = 0;
    }
};

class trie
{
public:
    trieNode *root;

    trie()
    {
        root = new trieNode('\0');
    }

    void insert(string s)
    {
        trieNode *curr = root;

        for (int i = 0; i < s.length(); i++)
        {
            if (curr->children[s[i] - 'a'] == NULL) // not avilable
            {
                trieNode *temp = new trieNode(s[i]);
                curr->children[s[i] - 'a'] = temp;
                curr = curr->children[s[i] - 'a'];
            }
            else
            {
                curr = curr->children[s[i] - 'a'];
            }
        }
        curr->isterminal = 1;
    }

    /*
       --------------------- INSERT USING RECURTION -----------------------
       void insert(trieNode* root,string word)
       {
        if(word.length() == 0)
        {
            root->isterminal = 1;
        }

        int index = word[0] - 'A';  //for capital letter
        trieNode* child;

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new trieNode(word[0]);
            root->children[index] = child;
        }

        insert(child,word.substr(1));
       }
    */

    bool search(string s)
    {
        trieNode *curr = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (curr->children[s[i] - 'a'] == NULL)
            {
                return 0;
            }
            else
            {
                curr = curr->children[s[i] - 'a'];
            }
        }

        if (!curr->isterminal)
        {
            return 0;
        }
        return 1;
    }

    /*
    ,,,,,,,,,,,,,,,,,,,,,, SEARCH USING RECURSION ,,,,,,,,,,,,,,,,,,,,,,,
    bool search(trieNode* root,string word)
    {
        if(word.length() == 0)
        {
            return root->isterminal;
        }

        int index = word[0] - 'A';  //for capital letter

        if(root->children[index] == NULL)
        {
            return false;
        }
        else
        {
            return search(root->children[index],word.substr(1));
        }
    }
    */

    void remove(string s)
    {
        trieNode *curr = root;

        for (int i = 0; i < s.length(); i++)
        {
            if (curr->children[s[i] - 'a'] == NULL)
            {
                cout << "WORD DOES NOT EXIST\n";
                return;
            }
            curr = curr->children[s[i] - 'a'];
        }
        curr->isterminal = false;
    }

    /*
   ,,,,,,,,,,,,,,,,,,,,,, REMOVE USING RECURSION ,,,,,,,,,,,,,,,,,,,,,,,
   void remove(trieNode* root,string s)
   {
       if(word.length() == 0)
       {
           root->isterminal = false;
           return;
       }

       int index = word[0] - 'A';  //for capital letter

       if(root->children[index] == NULL)
       {
           cout << "WORD DOES NOT EXIST\n";
           return;
       }
       else
       {
           search(root->children[index],word.substr(1));
       }
   }
   */

    bool startsWith(string s)
    {
        trieNode *curr = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (curr->children[s[i] - 'a'] == NULL)
            {
                return 0;
            }
            else
            {
                curr = curr->children[s[i] - 'a'];
            }
        }

        return 1;
    }

    // Implement a phone directory
    void printsuggestion(trieNode *root, vector<string> &temp, string prifix)
    {
        if (root->isterminal)
        {
            temp.push_back(prifix);
        }

        for (char i = 'a'; i < 'z'; i++)
        {
            if (root->children[i - 'a'] != NULL)
            {
                prifix.push_back(i);
                printsuggestion(root->children[i - 'a'], temp, prifix);
                prifix.pop_back();
            }
        }
    }

    vector<vector<string>> getsuggestion(string q)
    {
        trieNode *prev = root;
        vector<vector<string>> ans;
        string prifix = "";

        for (int i = 0; i < q.length(); i++)
        {
            prifix.push_back(q[i]);

            trieNode *curr = prev->children[q[i] - 'a'];

            if (curr == NULL)
            {
                break;
            }

            vector<string> temp;
            printsuggestion(curr, temp, prifix);
            ans.push_back(temp);
            prev = curr;
        }
        return ans;
    }
};

// longest common prifix
string commonprifix(vector<string> &v, int n)
{
    string ans = "";

    for (int i = 0; i < v[0].length(); i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (v[j].length() < i || v[j][i] != v[0][i])
            {
                return ans;
            }
        }
        ans.push_back(v[0][i]);
    }
    return ans;
}
/* (SHOWES TLE FOR BIG INPUT)  //plateform problem 
---------------------------- USING TRIE -------------------------------
class trieNode
{
public:
    char data;
    trieNode *children[26];
    bool isterminal;
    int count_child;

    trieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        this->isterminal = 0;
        this->count_child = 0;
    }
};

class trie
{
public:
    trieNode *root;

    trie()
    {
        root = new trieNode('\0');
    }

    void insert(string s)
    {
        trieNode *curr = root;

        for (int i = 0; i < s.length(); i++)
        {
            if (curr->children[s[i] - 'a'] == NULL)
            {
                trieNode *temp = new trieNode(s[i]);
                curr->children[s[i] - 'a'] = temp;

                curr->count_child++;

                curr = curr->children[s[i] - 'a'];
            }
            else
            {
                curr = curr->children[s[i] - 'a'];
            }
        }
        curr->isterminal = 1;
    }

    void maxi(string &s,string &ans)
    {
        for(int i = 0; i < s.length(); i++)
        {
            int index = s[i] - 'a';
            if(root->count_child == 1)
            {
                ans.push_back(s[i]);
                root = root->children[index];
            }
            else
            {
                break;
            }
            if(root->isterminal)
            {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &v, int n)
{
    // Write your code here
    string ans = "";
    trie* t = new trie();

    for (int j = 0; j < n; j++)
    {
        t->insert(v[j]);
    }

    t->maxi(v[0],ans);
    return ans;
}
*/

// Implement a phone directory
// suggest all the possible string with prifix q
vector<vector<string>> phoneDirectory(vector<string> &v, string &q)
{
    trie *t = new trie();

    for (auto a : v)
    {
        t->insert(a);
    }
    return t->getsuggestion(q);
}

int main()
{
    cout << "comencing operation\n";
    trie *t = new trie();

    t->insert("ayush");
    t->insert("arm");
    t->insert("time");
    t->insert("do");
    // cout << t->search("ayush") << endl;
    // t->remove("ayuh");
    // cout << t->search("ayush") << endl;
    // cout << t->search("arm") << endl;
    // cout << t->search("d") << endl;
    // cout << t->search("tine") << endl;
    return 0;
}