//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    vector<int> dp;
    int rec(int n ,int x,int y, int z)
    {
        if(n==0)return 0;
        else if(n<0) return -1e9;
        int take = -1e9;
        if(dp[n]!=-1)return dp[n];
        take = max(take,1+rec(n-x,x,y,z));
        take = max(take,rec(n-y,x,y,z)+1);
        take = max(take,rec(n-z,x,y,z)+1);
        if(n==x || n==y || n==z)
        {
            // cout << n << endl;
            take = max(take,1);
        }
        
        return dp[n] = take;
        
        
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        dp.assign(n+1,-1);
        int ans = rec(n,x,y,z);
        if(ans<=0)return 0;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends