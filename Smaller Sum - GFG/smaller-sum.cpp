//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
       vector<long long> sumarray;
       vector<int> lol=arr;
       sort(arr.begin(), arr.end());
      
       unordered_map<long long ,long long> map;
       
       long long sum=0;
       
           for(int i=0; i<n; i++)
           {
               
               sumarray.push_back(sum);
               sum=sum+arr[i];
           }
        for(int i=0; i<n; i++)
        {
            int index=lower_bound(arr.begin(), arr.end(), arr[i])-arr.begin();
            map[arr[i]]=sumarray[index];
        
        }
        vector<long long> ans;
        for(int i=0; i<n; i++)
        ans.push_back(map[lol[i]]);
        
       
       return ans;
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends