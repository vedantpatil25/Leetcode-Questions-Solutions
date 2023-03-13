//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int maxCoins(int N, vector<int>& a) {
            int n = a.size();
            vector<int> A(n+2, 1);
            for(int i = 0; i < n; i++) A[i+1] = a[i];
            vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
            for(int len = 1; len <= n; len++) {
                for(int left = 1; left <= n-len+1; left++) {
                    int right = left + len - 1;
                    for(int i = left; i <= right; i++) {
                        dp[left][right] = max(dp[left][right], A[left-1]*A[i]*A[right+1] + dp[left][i-1] + dp[i+1][right]);
                    }
                }
            }
            return dp[1][n];
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends