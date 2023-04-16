//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        // Write Your Code here
        int sieve[10001];
        for(int i = 0 ; i <= n ; i++)
        {
            sieve[i] = 1;
        }
        sieve[0] = 0;
        sieve[1] = 0;
        
        for(int i = 2 ; (i*i) <= n ; i++)
        {
            if(sieve[i] == 1)
            {
                for(int j = (i*i) ; j <= n ; j += i)
                {
                    sieve[j] = 0;
                }
            }
        }
        // for(int i = 0 ; i <= n ; i++)
        // {
        //     cout<<sieve[i]<<" ";
        // }
        // cout<<endl;
        
        vector<int>ans;
        for(int i = 0 ; i <= n ; i++)
        {
            if(sieve[i] == 1) ans.push_back(i);
        }
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends