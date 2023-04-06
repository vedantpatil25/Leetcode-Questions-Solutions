//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        //code here
        int n = str.size();
        int l = 0;
        int r = n - 1;
        
        int lastnotequal = r;
        
        while(l <= r)
        {
            if(str[l] == str[r])
            {
                l++;
                r--;
            }
            else
            {
                lastnotequal--;
                l = 0;
                r = lastnotequal;
            }
        }
        return (n - 1 - lastnotequal);
        
    }
};


//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends