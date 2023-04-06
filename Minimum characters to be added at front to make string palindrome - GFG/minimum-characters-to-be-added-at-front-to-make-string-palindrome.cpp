//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {

public:

    int lps(string s) {

     // Your code goes here

     int n=s.length();

     vector<int>dp(n,0);

     for(int i=1;i<n;i++){

         int j=dp[i-1];

         while(j>0 && s[i]!=s[j])

             j=dp[j-1];

         if(s[i]==s[j])

             j++;

         dp[i]=j;

     }

     return dp[n-1];

 }

    int minChar(string s){

        //Write your code here

        // reverse(s.begin(),s.end());

        string rev=s;

        reverse(rev.begin(),rev.end());

        string str=s+rev;

        return s.length()-lps(str);

    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends