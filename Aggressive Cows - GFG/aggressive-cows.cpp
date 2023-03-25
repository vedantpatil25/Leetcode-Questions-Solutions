//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool canPlace(vector<int>&stalls, int n, int k, int mid)
    {
        int cows = 1;
        int temp = stalls[0];
        for(int i = 1 ; i < n ; i++)
        {
            int dist = stalls[i] - temp;
            if(mid <= dist)
            {
                cows++;
                temp = stalls[i];
            }
            if(cows == k)
            {
                return true;
            }
        }
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        sort(stalls.begin(), stalls.end());
        if(n < k) return -1;
        int low = 0 ;
        int high = stalls[n-1] - stalls[0];
        int ans = INT_MIN; 
        while(low <= high)
        {
            int mid = ((high-low)/2) + low;
            // cout<<"mid: "<<mid<<endl;
            if(canPlace(stalls, n, k, mid))
            {
                // cout<<"h";
                ans = max(mid, ans);
                // cout<<"ans: "<<ans<<endl;

                low = mid+1;
                // cout<<"low: "<<low<<endl;
            }
            else
            {
                // cout<<"a";
                high = mid-1;
                // cout<<"high: "<<high<<endl;
            }
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends