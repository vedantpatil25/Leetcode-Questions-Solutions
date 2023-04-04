//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int cnt_b = 0;
    int cnt_a = 0;
    int n = str.size();
    for(int i = 0; i < n ; i++)
    {
        if(str[i] == 'a')
        {
            cnt_a++;
            while(i < n && str[i] == str[i+1]) i++;
        }
        else
        {
            cnt_b++;
            while(i < n && str[i] == str[i+1]) i++;
        }
    }
    // cout<<cnt_a<<" "<<cnt_b<<endl;
    return min(cnt_a, cnt_b) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends