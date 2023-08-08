//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int nt[], int d[])
    {
        int ans = 0; 
        map<pair<int, int>, int> fre;
        
        for(int i=0;i<n;i++){
            int gcd = __gcd(nt[i], d[i]);
            
            nt[i]/=gcd;
            d[i]/=gcd;
            
            if(fre.find({d[i] - nt[i], d[i]}) != fre.end()){
                ans += fre[{d[i] - nt[i], d[i]}];
            }
            
            fre[{nt[i], d[i]}]++;
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
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends