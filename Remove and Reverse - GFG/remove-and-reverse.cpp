//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        int n=S.size();
        
        int i=0;
        int j=n-1;
        vector <int> vec(26,0);
        for(char ch: S){
            vec[ch-'a']++;
        }
        bool can=true;
        string ans="";
        string ans1="";
        vector <bool> vis(n,false);
        while(i<=j)
        {
            if(can)
            {
                char ch=S[i];
                if(vec[ch-'a']==1){
                    vis[i]=true;
                    i++;
                }
                else{
                    i++;
                    can=false;
                }
                vec[ch-'a']--;
            }
            else{
                char ch=S[j];
                if(vec[ch-'a']==1){
                    vis[j]=true;
                    j--;
                }
                else{
                    j--;
                    can=true;
                }
                vec[ch-'a']--;
            }
            
        }
        for(int i = 0 ; i <= n; i++)
        {
            if(vis[i] == true) ans += S[i];
        }
        if(!can) reverse(ans.begin(), ans.end());
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