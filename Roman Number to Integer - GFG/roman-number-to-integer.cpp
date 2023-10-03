//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        map<char,int>hash;
        hash['I']=1;
        hash['V']=5;
        hash['X']=10;
        hash['L']=50;
        hash['C']=100;
        hash['D']=500;
        hash['M']=1000;
        int n=s.size();
        int ans=0;

        int i=0;
        while(i<=n-1){
            if(hash[s[i]]<hash[s[i+1]]){
                ans+=abs(hash[s[i]]-hash[s[i+1]]);
                i+=2;
            }
            else
            {
                ans+=hash[s[i]];
                i++;
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends