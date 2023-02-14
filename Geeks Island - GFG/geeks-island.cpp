//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
  int water_flow(vector<vector<int>> &v, int n, int m)
  {
    // Write your code here.
    n = v.size();
    m = v[0].size();
    bool a[n][m];
    bool b[n][m];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        a[i][j] = false;
        b[i][j] = false;
      }
    }
    queue<pair<int, int>> q, d;
    for (int i = 0; i < n; i++)
    {
      q.push({i, 0});
      d.push({i, m - 1});
      a[i][0] = true;
      b[i][m - 1] = true;
    }
    for (int i = 0; i < m; i++)
    {
      a[0][i] = true;
      b[n - 1][i] = true;
      q.push({0, i});
      d.push({n - 1, i});
    }
    while (q.size())
    {
      auto k = q.front();
      q.pop();
      int x = k.first;
      int y = k.second;
      int dx[4] = {1, -1, 0, 0};
      int dy[4] = {0, 0, 1, -1};
      for (int i = 0; i < 4; i++)
      {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == false && v[x][y] <= v[nx][ny])
        {
          a[nx][ny] = true;
          q.push({nx, ny});
        }
      }
    }
    while (d.size())
    {
      auto k = d.front();
      d.pop();
      int x = k.first;
      int y = k.second;
      int dx[4] = {1, -1, 0, 0};
      int dy[4] = {0, 0, 1, -1};
      for (int i = 0; i < 4; i++)
      {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && b[nx][ny] == false && v[x][y] <= v[nx][ny])
        {
          b[nx][ny] = true;
          d.push({nx, ny});
        }
      }
    }
    int tt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (a[i][j] && b[i][j])
          tt++;
      }
    }
    return tt;
  }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends