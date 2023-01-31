//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
        if(A == B) return 1;
        int lenA = A.size();
        int lenB = B.size();
        
        string temp = A;
        int ans =1;
        while(temp.size() <= B.size())
        {
            if(temp.size() == B.size() & temp == B) return ans;
            temp += A;
            ans++;
        }
        if(temp.find(B) != -1)
        {
            return ans;
        }
        if(A.size() > B.size())
        {
            temp += A;
            ans++;
            if(temp.find(B) != -1) return ans; 
        }
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends