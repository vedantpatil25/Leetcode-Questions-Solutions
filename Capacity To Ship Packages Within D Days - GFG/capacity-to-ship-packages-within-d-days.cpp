//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    bool canLoad(int arr[], int n, int d, int mid)
    {
        int days = 0;
        int curr_w = 0;
        for(int i = 0 ; i < n ; i++)
        {
            curr_w += arr[i];
            if(curr_w > mid)
            {
                days++;
                curr_w = arr[i];
            }
        }
        days++;
        return (days <= d);
    }
  
  
    int leastWeightCapacity(int arr[], int n, int d) {
        if(n<d) return -1;
        int ans = INT_MAX;
        int sum = accumulate(arr,arr+n,0);
        int maxx = *max_element(arr,arr+n);
        
        int low = maxx;
        int high = sum;
        
        while(low <= high)
        {
            int mid = ((high-low)/2) + low;
            if(canLoad(arr,n,d,mid))
            {
                // cout<<"h";
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
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
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends