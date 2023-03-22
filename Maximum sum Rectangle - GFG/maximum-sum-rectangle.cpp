//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(vector<int>&vec)
    {
        int n = vec.size();
        int sum = INT_MIN;
        int curr = 0;
        for(int i=0; i<n; i++){
            curr += vec[i];
            sum = max(sum, curr);
            if(curr<0) curr=0;
        }
        return sum;
    }
    int maximumSumRectangle(int r, int c, vector<vector<int>> mat) {
        // code here
        int ans = INT_MIN;
        for(int i = 0 ; i < r; i++)
        {
            vector<int>vec(c);
            for(int j = i ; j < r ; j++)
            {
                for(int k = 0 ; k < c ; k++)
                {
                    vec[k] += mat[j][k];
                }
                int temp = f(vec);
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends