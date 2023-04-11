//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &v){
        // Code here
        int count=0;
        sort(v.begin(), v.begin()+n/2);
        sort (v.begin()+n/2, v.end());
        int i=(n/2)-1,j=n-1;
        
        while(i>=0 and j>=n/2){
            if(v[i]>=5*v[j]){
                count+=j-n/2+1;
                i--;
            }
            else{
                j--;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends