//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector<int> findMean(int arr[],int queries[],int n,int q)
    {
        // Complete the function
        vector<int> ans;
        int prefixSum[n];
        prefixSum[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            prefixSum[i]=prefixSum[i-1]+arr[i];
        }
        
        for(int i=0;i<q;i=i+2)
        {
            int sum=0;
            int l=queries[i];
            int r=queries[i+1];
            if(l==0) sum=prefixSum[r];
            else sum=prefixSum[r]-prefixSum[l-1];
            int mean=sum/(r-l+1);
            ans.push_back(mean);
        }
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
        int n,q;
        cin>>n>>q;
        int arr[n + 1],queries[2*q + 1];

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        for(int i=0;i<2*q;i++){
            cin>>queries[i];
        }

        vector<int> ans;
        Solution ob;
        ans = ob.findMean(arr,queries,n,2*q);

        for(int i:ans)
            cout<<i<<" ";
        cout<<endl;

    }
    return 0;
}

// } Driver Code Ends