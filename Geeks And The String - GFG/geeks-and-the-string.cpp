//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string str) {
        // code here
        stack<char>s;
        int n = str.size();
        for(int i = 0 ; i < n ; i++)
        {
             if(s.empty())
             {
                 s.push(str[i]);
             }
             else
             {
                 (s.top() == str[i]) ? s.pop() : s.push(str[i]);
             }
        }
        string ans="";
        while(!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        // cout<<"ans is "<<ans<<endl;
        reverse(ans.begin() , ans.end());
        if(ans.size() != 0)  return ans;
        else return "-1";
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends