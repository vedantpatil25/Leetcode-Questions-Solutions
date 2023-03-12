//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {

  public:

    long long maxPossibleValue(int n,vector<int> a, vector<int > b) {

       int previous=1e9;

       long long ans=0,count=0;

       for(int i=0;i<n;i++){

           if(b[i]%2) b[i]--;

            count+=b[i];

            ans+=b[i]*a[i];

            if(b[i])  previous=min(previous,a[i]);

       }

       if(count%4==0)   return ans;

       else  return ans-2*previous;

    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends