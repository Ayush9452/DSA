#include <bits/stdc++.h>
using namespace std;

/*
   -: INPUT INSTRUCTIONS :- 
   The first line of input contains the number of groups in which users are divided.
   First line of each group contains the number of friends that belong to that group.
   ith line of each group contains the space separated friend list of 'i'.
   You are assured that each friend's profile can be accessed by the profile of every
   other friend by following some sequence of profile visits.

   -: INPUT :-
   1
   3
   5
   6
   1 4
   3 5 6
   2 4 6
   4 5
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int n;
        cin >> n;
        vector<int> graph[n];
        getline(cin, s);
        for (int i = 0; i < n; i++)
        {
            getline(cin, s);
            int c = 0;
            for (int j = 0, l = s.length(); j < l; j++)
            {
                if (s[j] == ' ')
                {
                    graph[i].push_back(c);
                    c = 0;
                }
                else
                {
                    c = (c * 10) + (s[j] - '0');
                }
            }
            graph[i].push_back(c);
        }
    }
    return 0;
}