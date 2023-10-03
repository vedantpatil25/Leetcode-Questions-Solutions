//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string rec(long long int n){
        if(n == 0){
            return "";
        }
        
        if(n%26 == 0) return rec((n/26) - 1) + "Z";
        
        return rec(n/26) + (char) ((n-1)%26 + 'A');
    }
    string colName (long long int n)
    {
        // your code here
        string ans = rec(n);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends