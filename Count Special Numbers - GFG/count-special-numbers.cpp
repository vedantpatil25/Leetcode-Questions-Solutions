//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        int ans = 0;
        unordered_map<int, int>m;
        for(auto x : arr) m[x]++;
        
        for(auto it : m)
        {
            int num = it.first;
            int freq = it.second;
            if(freq > 1)
            {
                ans += freq;
            }
            else
            {
                for(auto temp : arr)
                {
                    if((num != temp) && (num%temp == 0))
                    {
                        ans++;
                        break;
                    }
                }
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends