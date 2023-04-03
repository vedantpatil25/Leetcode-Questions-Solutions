//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
       // code here
       int osum = 0, esum = 0;
       int n = x.size();
       for(int i = 0 ; i < n ; i++)
       {
           if((i&1) == 0) esum += (x[i] - '0');
           else osum += (x[i] - '0');
       }
       
       int ans = (osum - esum)%11;
       
       return (ans < 0) ? (ans+11) : ans ;
       
    
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends