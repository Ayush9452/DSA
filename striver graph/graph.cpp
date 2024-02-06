#include <bits/stdc++.h>
using namespace std;


class Solution 
{
    vector<pair<int,int>> neighbour(pair<int,int> temp)
    {
        int x = temp.first;
        int y = temp.second;
        
        vector<pair<int,int>> ans(8);
        ans[0] = {x,y - 1};
        ans[1] = {x,y + 1};
        
        ans[2] = {x - 1,y};
        ans[3] = {x + 1,y};
        
        ans[4] = {x + 1,y - 1};
        ans[5] = {x + 1,y + 1};
        
        ans[6] = {x - 1,y - 1};
        ans[7] = {x - 1,y + 1};
        
        return ans;
    }
    
    bool isposs(pair<int,int> temp,int n,int m,vector<vector<int>> &visited,vector<vector<char>>& grid)
    {
        int i = temp.first;
        int j = temp.second;
        
        if((i < n && i >= 0) && (j < m && j >= 0))
        {
            return ((visited[i][j] == 0) && (grid[i][j] == '1'));
        }
        
        return 0;
        
    }
    
    void BFS(vector<vector<char>>& grid,int i,int j,vector<vector<int>> &visited)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = 1;
        
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty())
        {
            pair<int,int> front = q.front();
            q.pop();
            
            vector<pair<int,int>> temp = neighbour(front);
            
            for(int k = 0;k < 8;k++)
            {
                if(isposs(temp[k],n,m,visited,grid))
                {
                    q.push(temp[k]);
                    visited[temp[k].first][temp[k].second] = 1;
                }
            }
        }
    }
    
  public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        int cnt = 0;
        
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    BFS(grid,i,j,visited);
                }
            }
        }
        
        return cnt;
    }
};

class Solution
{
    vector<pair<int,int>> neighbour(pair<int,int> temp)
    {
        int x = temp.first;
        int y = temp.second;
        
        vector<pair<int,int>> ans(8);
        
        ans[0] = {x,y - 1};
        ans[1] = {x,y + 1};
        
        ans[2] = {x - 1,y};
        ans[3] = {x + 1,y};
        
        return ans;
    }
    
    bool isposs(pair<int,int> temp,int n,int m,vector<vector<int>> &visited,vector<vector<int>>& grid,int color)
    {
        int i = temp.first;
        int j = temp.second;
        
        if((i < n && i >= 0) && (j < m && j >= 0))
        {
            return ((visited[i][j] == 0) && (grid[i][j] == color));
        }
        
        return 0;
        
    }
    
    void BFS(vector<vector<int>>& grid,int i,int j,vector<vector<int>> &visited,int newcolor)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        visited[i][j] = 1;
        int color = grid[i][j];
        
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty())
        {
            pair<int,int> front = q.front();
            q.pop();
            
            grid[front.first][front.second] = newcolor;
            
            
            vector<pair<int,int>> temp = neighbour(front);
            
            for(int k = 0;k < 4;k++)
            {
                if(isposs(temp[k],n,m,visited,grid,color))
                {
                    q.push(temp[k]);
                    visited[temp[k].first][temp[k].second] = 1;
                }
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> ans(image);
        
        BFS(ans,sr,sc,visited,newColor);
        
        return ans;
    }
};

int main()
{
    
    return 0;
}
