//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        //code here
        int n = str.size();
        int l = 0;
        int r = n - 1;
        
        int ans = 0;
        int temp = r;
        while(l <= r)
        {
            if(str[l] == str[r])
            {
                l++;
                r--;
            }
            else
            {
                ans++;
                l = 0;
                temp--;
                r  = temp;
            }
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
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends