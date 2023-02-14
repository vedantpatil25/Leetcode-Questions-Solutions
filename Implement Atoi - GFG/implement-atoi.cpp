//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans = 0;
        int first = (str[0] == '-') ? 1:0;
        int n = str.size() - 1;
        for(int i = first ; i <= n ; i++)
        {
            if(str[i] <= '9' && str[i] >= '0')
                ans = ans*10 + (str[i]-'0');
            else return -1;
        }
        if(first == 1) ans = -ans;
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends