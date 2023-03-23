//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        // code here
        int l = 0;
        int r = s.size()-1;
        string ans1 = "";
        string ans2 = "";
        
        unordered_map<char, int>mp;
        for(auto x: s) mp[x]++;
        bool flag = true;
        
        while(l<=r)
        {
            if(flag)
            {
                if(mp[s[l]] > 1)
                {
                    mp[s[l]]--;
                    flag = false;
                    
                }
                else ans1+=s[l];
                l++;
                
            }
            else
            {
                if(mp[s[r]] > 1)
                {
                    mp[s[r]]--;
                    flag = true;
                }
                else ans2=s[r] + ans2;
                r--;
            }
        }
        string ans = ans1+ans2;
        if(!flag) reverse(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends