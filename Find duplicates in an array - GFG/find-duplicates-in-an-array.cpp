//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int>v;
        
        int a2[n]={0};
        for(int i=0;i<n;i++)
        {
            a2[arr[i]]++;
        }
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(a2[i]>1){
            v.push_back(i);
            flag++;}
        }
        if(flag==0) 
        v.push_back(-1);
        
        return v;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends