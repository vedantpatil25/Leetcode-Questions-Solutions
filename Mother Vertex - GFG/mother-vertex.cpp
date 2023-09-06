//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	 void dfs(int node,vector<int>&vis,vector<int>adj[])
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            dfs(it,vis,adj);
        }
    }
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	   int ans=-1;
	   vector<int>vis(V,0);
	   for(int i=0;i<V;i++)
	   {
	       if(!vis[i])
	       {
	           dfs(i,vis,adj);
	           ans=i;
	       }
	   }
	   vector<int>vis2(V,0);
	   dfs(ans,vis2,adj);
	   
	   for(auto x:vis2)
	   {
	       if(x==0)return -1;
	   }
	   
	   return ans;
	}


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends