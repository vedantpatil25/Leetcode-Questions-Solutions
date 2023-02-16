//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum)
    {
        if(K >= N)
        {
            return GeekNum[N-1];
        }
        
        vector<long long>ans(N, 0);
        long long sum = 0;
        for(int i = 0 ; i < K ; i++)
        {
            sum += GeekNum[i];
            ans[i] = GeekNum[i];
        }
        ans[K] = sum;
        
        for(int i = K+1 ; i < N; i++)
        {
            sum += sum - ans[i-K-1];
            ans[i] = sum;
        }
        int temp = ans.size(); 
        return ans[temp-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends