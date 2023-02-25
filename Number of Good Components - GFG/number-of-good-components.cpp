//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
void dfs(int src,vector<vector<int>> &adj,vector<bool> &vis,int &count,int &edge)

  {

      vis[src]=1;

      count++;

      for(auto it:adj[src])

      {

          edge++;

          if(!vis[it])

            dfs(it,adj,vis,count,edge);

      }

  }

    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {

        // code here

        vector<bool> vis(V+1,0);

        int count,edges,res=0;

        for(int i=1;i<=V;i++)

        {

            if(!vis[i])

         {

            count=0,edges=0;

            dfs(i,adj,vis,count,edges);

            if(edges/2 == (count*(count-1)/2))

                res++;

            }

        }

        return res;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends