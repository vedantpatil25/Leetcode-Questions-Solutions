//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

         int mod = 1e9 + 7;
    int countPaths(int n){
        // code here 
        if (n == 1) return 0;
        unsigned long long int ans = 3;
        for (int i = 3; i <= n; i++)    {
            ans *= 3;
            (i%2)? ans -= 3 : ans += 3;
            ans = ans%int(mod);
        }
        return int(ans);
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
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends