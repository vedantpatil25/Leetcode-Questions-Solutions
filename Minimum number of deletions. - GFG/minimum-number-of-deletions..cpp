//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

int memo[1001][1001];
   
   int lcs(int x, int y , string &s1 , string &s2 )
    {
        if(x == 0 || y == 0 ) return 0;

        if(memo[x][y] != -1) return memo[x][y];
        
        if(s1[x-1] == s2[y-1]) return 1 + lcs(x-1, y-1, s1,s2);
        else return memo[x][y] = max(lcs(x-1, y, s1,s2), lcs(x, y-1, s1,s2));
    
    }

    int minDeletions(string a, int n) { 
        memset(memo, -1, sizeof(memo));
        string b = string(a.rbegin() , a.rend());
        // int n = a.size();
        int m = n;
        return  n - lcs(n, m, a, b);
} 