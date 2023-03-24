//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        // Code here.
        int n = arr.size();
        if(n == 1) return 0;
        int low=0, high=n-1;

       while(low<=high)
       {
           int mid = (high+low)/2;
           
           //ans criteria
           if((mid == 0 || arr[mid] >= arr[mid-1]) && (mid == n-1 || arr[mid] >= arr[mid+1]) )
           {
               return arr[mid];
           }
           
           //criteria to go right or left
           if(mid != 0 && (arr[mid-1] > arr[mid])) high = mid-1;
           else if(mid != n - 1 && (arr[mid+1] > arr[mid])) low = mid+1;
       }
       return -1;
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends