//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    // sum, start => ans
    vector<vector<long long int>> cache;
  public:
    Solution() {
        cache = vector<vector<long long int>>(1001, vector<long long int>(1001, -1));
    }

    long long int count(int coins[], int N, int sum, int start = 0) {
        //base
        if(sum == 0) return 1;
        if(sum < 0) return 0;
        
        if(cache[sum][start] >= 0) return cache[sum][start];

        // sub problwms
        long long int ans = 0;
        for(int i = start; i < N; ++i) {
            ans += count(coins, N, sum - coins[i], i);
        }
        
        return cache[sum][start] = ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends