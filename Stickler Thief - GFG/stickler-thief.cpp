//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int solve(int ind , int *arr, vector<int>&dp)
	{
	    if(ind == 0 ) return arr[ind];
	    if(ind < 0) return 0;
	    
	    if(dp[ind] != -1) return dp[ind];
	    
	    int pick = arr[ind] + solve(ind-2, arr, dp);
	    int notPick = solve(ind-1, arr, dp);
	    return dp[ind] = max(pick, notPick);
	}
	
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> temp1,temp2;
        
        for(int i =0 ; i < n ; i++)
        {
            if(i != 0 ) temp1.push_back(arr[i]);
            if(i != n-1 ) temp1.push_back(arr[i]);
        }
        vector<int>dp1(n+1 , -1);
        vector<int>dp2(n+1 , -1);
	    return max( solve(n-1 , arr , dp1) ,  solve(n-1 , arr , dp2) );
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends