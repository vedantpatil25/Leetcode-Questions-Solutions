//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<bool>visited(leaves+1,false);
        
        for(int i = 0 ; i < N ; i++)
        {
            int temp = frogs[i];
            if(visited[temp] == false && temp <= leaves)
            {
                for(int j = temp ; j <= leaves ; j += temp)
                {
                    if(j <= leaves) visited[j] = true;
                }   
            }
        }
        int ans = 0;
        for(auto x : visited) if(x == false) ans++;
        
        return --ans;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends