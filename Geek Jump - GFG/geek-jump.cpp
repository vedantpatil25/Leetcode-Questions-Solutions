//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int solve(vector<int>& height, int curr, vector<int>&dp){
        if(curr == 0) return 0;
        if(dp[curr] != -1) return dp[curr]; 
        
        int left = solve(height, curr-1, dp) + abs(height[curr] - height[curr-1]);
        int right = INT_MAX;
        
        if(curr > 1) right = solve(height, curr-2, dp) + abs(height[curr] - height[curr-2]);
        
        return dp[curr] =  min(left, right);
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1, -1);
        return solve(height, n-1, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends