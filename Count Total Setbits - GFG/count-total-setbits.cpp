//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long N) {
        // code here
        long long ans = 0;
        N++;
        for (int i = 0; i < 30; i++)
        {
            long long p = pow(2, i + 1);
            ans += (N/p)*(p/2);
            long long r = (N % p) - p/2;
            if (r >= 0)
            ans += r;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends