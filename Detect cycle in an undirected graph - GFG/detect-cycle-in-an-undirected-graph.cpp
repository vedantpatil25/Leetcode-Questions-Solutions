//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool BFS(vector<int> adj[] ,int s , vector<bool>&visited )
    {
        unordered_map<int , int>m;
        m[s] = -1;
        visited[s]=true;
        queue<int>q;
        q.push(s);
        
        while(q.empty() == false)
        {
            int temp = q.front();
            q.pop();
            
            for(int &val : adj[temp])
            {
                //condition to be a graph cyclic......is below
                //condition is : if val is already visited by someone else before temp and is again trying to visit it that means it is having a cycle
                if(visited[val] == true && val != m[temp])
                {
                    return true;
                }
                
                else if(visited[val] == false)
                {
                    q.push(val);
                    visited[val] = true;
                    m[val] = temp;
                }
            }
            
        }
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool>visited(V,false);
        
        //we are runnning this loop because it is possible that we may the multiple components so we are checking for every node
        for(int i = 0 ; i < V ; i++)
        {
            if(visited[i] == false)
            {
                if(BFS(adj,i,visited) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends