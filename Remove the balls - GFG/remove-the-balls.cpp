//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<pair<int,int>>s;
        s.push({color[0],radius[0]});
        int ans=0;
        for(int i=1;i<N;i++){
           
            if(s.empty()!=true){
               pair<int,int>p=s.top();        
               if(p.first==color[i] && p.second==radius[i]){
                   s.pop();
                 }else{
                     s.push({color[i],radius[i]});
                 }
            }else{
                s.push({color[i],radius[i]});
            }
        }
        
        while(s.empty()!=true){
            ans++;
            s.pop();
        }
        
        return ans;
    }
    
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends