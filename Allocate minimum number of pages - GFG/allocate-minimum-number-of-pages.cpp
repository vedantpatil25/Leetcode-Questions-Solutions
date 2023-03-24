//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

//self solu
class Solution 
{
    public:
    
    //fuction to check if given mid is valid or not
    bool canAllocate(int arr[], int n, int max, int k)
    {
        int student = 1;
        int curr_sum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            curr_sum += arr[i];
            if(curr_sum > max)
            {
                student++;
                curr_sum = arr[i];
            }
        }
        return (student<=k);
    }
    
    
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int k) 
    {
        //edge cases
        if(n<k) return -1;
        
        //finding the range of searching   (max <---> sum)
        int max_arr = INT_MIN;
        int sum_arr = 0;
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++)
        {
            max_arr = max(max_arr, arr[i]);
            sum_arr += arr[i];
        }
        
        //serching space
        int start = max_arr;
        int end = sum_arr;
        
        //calculating min possible 
        while(start <= end)
        {
            int mid =  ((end-start)/2) + start;
            if(canAllocate(arr,n ,mid, k))
            {
                // cout<<"hit";
                ans = min(ans, mid);
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends