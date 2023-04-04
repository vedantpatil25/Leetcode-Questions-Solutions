//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:

    void bfs(vector<int> adjlist[],vector<int> &vis, int node){
        vis[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int Node=q.front();
            q.pop();
            for(auto it: adjlist[Node]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjlist[V];
        for(int i=0;i<V;++i){
            for(int j=0;j<V;++j){
                if(adj[i][j]==1 && i!=j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        int count=0;
        
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                count++;
                bfs(adjlist,vis,i);
            }
        }
        return count;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends