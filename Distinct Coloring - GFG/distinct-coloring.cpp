//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

#define ll long long int

class Solution{   
public:
    ll mini(ll a,ll b)
    {
       if(a>b) return b;
       return a;
    }
    long long int distinctColoring(int N, int r[], int g[], int b[])
    {
        // code here 
        vector<ll>R(N);
        vector<ll>G(N);
        vector<ll>B(N);
        R[0]=r[0];
        G[0]=g[0];
        B[0]=b[0];
        for(int i=1;i<N;i++)
        {
           R[i]=r[i]+mini(G[i-1],B[i-1]);
           G[i]=g[i]+mini(R[i-1],B[i-1]);
           B[i]=b[i]+mini(R[i-1],G[i-1]);
        }
        return mini(R[N-1],mini(G[N-1],B[N-1]));
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends