//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>&visited,vector<vector<char>>grid,int row,int col)
    {
        visited[row][col]='1';
        
        int n=grid.size();
        int m=grid[0].size();
        
        //traverse the neighboures of 1
        
        for(int delrow=-1;delrow<=1;delrow++)
        {
            for(int delcol=-1;delcol<=1;delcol++)
            {
                int newrow=row+delrow;
                int newcol=col+delcol;
                
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && 
                   !visited[newrow][newcol] && grid[newrow][newcol]=='1')
                   {
                       dfs(visited,grid,newrow,newcol);
                   }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<char>>visited(n,vector<char>(m,0));
        int count=0;
        
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(!visited[row][col] && grid[row][col]=='1')
                {
                    dfs(visited,grid,row,col);
                    count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends