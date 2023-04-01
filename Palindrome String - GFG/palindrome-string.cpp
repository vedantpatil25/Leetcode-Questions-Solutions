//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool helper(string &s, int l,int r)
    {
        // cout<<l<<" "<<r<<endl;
        if(r-l <= 1) return s[l] == s[r];

        if(s[l] != s[r]) return false;
        return helper(s, l+1, r-1);
    }
	
	int isPalindrome(string s)
	{
	    // Your code goes here
	    int n = s.size();
        return helper(s,0 ,n-1);
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends