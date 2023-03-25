//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution{
public:
    int countBits(int N, long long int A[])
    {
        // code here
        long long ans = 0;
        for(int i = 0 ; i < 32; i++)
        {
            long long set = 0;
            long long unset = 0;
            for(int j = 0 ; j  < N ; j++)
            {
                if(A[j] & (1<<i)) set++;
                else unset++;
            }
            ans = (ans+((set*unset*2)%1000000007))%1000000007;
            ans = ans%1000000007;
        }
        return (int)ans%1000000007;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends