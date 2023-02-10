//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        map<char , int>m;
        for(auto val: s)
        {
            if(val == 'b' || val == 'a' ||val == 'l' ||val == 'o' ||val == 'n')
            m[val]++;
        }
        if(m['l'] > 0)
            m['l'] /= 2;
        if(m['o'] >0)
            m['o'] /= 2;
        int minn = INT_MAX;
        string temp = "balon";
        for(auto it: temp)
        {
            if(m.find(it) == m.end()) return 0;
            minn = min(minn , m[it]);
        }
    
        return minn;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends