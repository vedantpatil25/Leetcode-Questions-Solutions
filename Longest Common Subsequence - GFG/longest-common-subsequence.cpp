//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int helper(int x, int y , string s1 , string s2 , vector<vector<int>> &memo)
    {
        if(x == 0 || y == 0 )
        {
            return 0 ;
        }
        if(memo[x][y] != -1)
        {
            return memo[x][y];
        }
        
        if(s1[x-1] == s2[y-1])
        {
            return 1 + helper(x-1, y-1, s1,s2,memo);
        }
        else
        {
            return memo[x][y] = max(helper(x-1, y, s1,s2,memo), helper(x, y-1, s1,s2,memo));
        }
    
    }
    
    
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>>memo(x+1,vector<int>(y+1,-1));
        return  helper(x,y,s1,s2,memo);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends