//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        int sum=0;
        int n=s.size();
        int i=0;
        while(s[i]=='?' && s[n-1-i]=='?')
        { i++;
        }
        if(i==n-1)
        return 0;
        
        for(int k=0;k<i;k++)
        {   if(s[i]!='?')
            {s[k]=s[i];
        s[n-1-k]=s[i];
                
            }
            else{
                s[k]=s[n-1-i];
        s[n-1-k]=s[n-1-i];
            }
            
            
        }
        int left=0,right=n-1;
        while(left<=right)
        {
            if(s[left]=='?' && s[right] !='?')
            {
                s[left]=s[right];
                left++;
                right--;
            }
           else if(s[left]!='?' && s[right] =='?')
            {
                s[right]=s[left];
                left++;
                right--;
            }
            else if((s[left]==s[right]) && (s[left]=='?' && s[right]=='?'))
            {   s[left]=s[left-1];
                s[right]=s[right+1];
                left++;
                right--;
                
            }
            else if((s[left]==s[right]) && (s[left]!='?'&&s[left]!='?' ))
            {
                left++;
                right--;
            }
            else
            return -1;
        }
        
        for(int j=0;j<n-1;j++)
        {
          sum+=abs(s[j]-s[j+1]);  
        }
        
        return sum;
         
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends