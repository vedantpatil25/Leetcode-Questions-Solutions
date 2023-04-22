//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
int memo[1001][1001];
class Solution{
  public:
   
   int lcs(int x, int y , string s1 , string s2 )
    {
        if(x == 0 || y == 0 )
        {
            return 0;
        }
        if(memo[x][y] != -1)
        {
            return memo[x][y];
        }
        
        if(s1[x-1] == s2[y-1])
        {
            return 1 + lcs(x-1, y-1, s1,s2);
        }
        else
        {
            return memo[x][y] = max(lcs(x-1, y, s1,s2), lcs(x, y-1, s1,s2));
        }
    
    }
  

    int longestPalinSubseq(string a) {
        //code here
        memset(memo, -1, sizeof(memo));
        string b = string(a.rbegin() , a.rend());
        int n = a.size();
        int m = n;
        
        return lcs(n, m, a, b);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends