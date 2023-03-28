//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        int n = S.size();
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            if(S[i]>='A' && S[i]<='Z') a[i] = 1;
            else a[i] = -1;
        }
        map<int, int> mp;
        int sum = 0, ans = 0;
        mp[0] = 1;
        for(auto& x: a) {
            sum += x;
            ans += mp[sum];
            ++mp[sum];
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends