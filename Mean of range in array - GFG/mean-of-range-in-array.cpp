//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
     vector<int> findMean(int arr[],int queries[],int n,int q)
    {
        vector<int>v;
        int j=-1;
        while(q)
        {
            j+=1;
            int l=queries[j];
            j+=1;
            int r=queries[j];
            int sum=0;
            int count=r-l+1;
            for(int i=l;i<=r;i++)
            {
                sum=sum+arr[i];
            }
            v.push_back(sum/count);
            q=q-2;
        }
        return v;
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