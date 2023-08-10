//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// TABULATION METHOD -->


class Solution {
  public:
    
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n, 0);
        dp[0] = 0;
        for(int i = 1 ; i < n ; i++){
            int fs = dp[i-1] + abs(height[i] - height[i-1]);
            int ls = INT_MAX;
            if(i > 1) ls = dp[i-2] + abs(height[i] - height[i-2]);
            
            dp[i] = min(ls, fs);
        }
        return dp[n-1];
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