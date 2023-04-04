//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int source, vector<int> adj[], vector<int>&ans, vector<bool>&vis)
    {
        queue<int>q;
        // cout<<"hit for " <<source<<endl;
        q.push(source);
        vis[source] = true;
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            
            for(auto &x : adj[temp])
            {
                if(vis[x] == false) 
                {
                    q.push(x);
                    vis[x] = true;
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        // Code here
        vector<bool>vis(V, false);
        vector<int>ans;
        // for(int i = 0 ; i < V ; i++)
        // {
        //     if(vis[i] == false)
        //     {
                bfs(0, adj, ans, vis);
        //         vis[i] = true;
        //     }
        // }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends