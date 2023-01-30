//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
c
lass Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int solve(vector<int>arr)
	{
	    int n = arr.size();
	    int prev = 0;
	    int prev2 = arr[0];
	    for(int i = 1 ; i < n ; i++)
	    {
	        int take = arr[i];
	        if(i>1) take += prev2;
	        int notTake = prev;
	        int curr = max(take, notTake);
	        
	        prev2 = prev;
	        prev = curr;
	    }
	    return prev;
	}
	
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n == 1) return arr[0];
        vector<int> temp1,temp2;
        for(int i =0 ; i < n ; i++)
        {
            if(i != 0 ) temp1.push_back(arr[i]);
            if(i != n-1 ) temp2.push_back(arr[i]);
        }
	    return max( solve(temp1) ,  solve(temp2) );
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