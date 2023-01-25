//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s)
    {
        // code here
        int n=s.size();
        if(n==1) return 1;
        int cnt = 0;
        for(int i = n ; i >= 0 ; i--) 
        {
            // cout<<"hit";
            // cout<<i<<endl;

            if(i%2 != 0)
            {
                cnt++;
            }
            else
            {
                string temp1 =  s.substr(0,(i/2));
                string temp2 = s.substr((i/2) ,(i/2));
                // cout<<temp1<<" "<<temp2<<endl;
                if((temp1) == (temp2) )
                {
                    return cnt += (i/2) + 1;
                }
                else
                {
                    cnt++;
                    
                }
            }
        }
        return cnt;

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
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends