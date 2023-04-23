//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) ans[i]=-1;
            else ans[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty())
            {
                if(ans[i]==-1) ans[i] = st.top();
                else
                {
                    int ind = st.top();
                    if((i-ind)<(ans[i]-i)) ans[i] = ind;
                    else if((i-ind)==(ans[i]-i)) if(arr[ind]<=arr[ans[i]]) ans[i] = ind;
                }
                
            }
            st.push(i);
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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends