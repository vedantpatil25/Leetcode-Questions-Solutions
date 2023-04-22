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

int t[1001][1001];

int LPS(string &s1, string &s2, int m, int n){
    if(m == 0 || n == 0) return 0;
    
    if(t[m][n] != -1) return t[m][n];
    
    if(s1[m-1] == s2[n-1]) return t[m][n] = 1 + LPS(s1, s2, m-1, n-1);
    else return t[m][n] = max(LPS(s1, s2, m-1, n), LPS(s1, s2, m, n-1));
}

int minDeletions(string str, int n) { 
    memset(t, -1, sizeof(t));
    
    string b = string(str.rbegin(), str.rend());
    
    return n - LPS(str, b, n, n);
} 