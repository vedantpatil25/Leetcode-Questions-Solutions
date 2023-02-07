//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // Function to return the length of the
    // longest subarray with ppositive product
    int maxLength(vector<int> &arr, int n)
    {
        vector<pair<int, int>> pre(n, {0, 0}), pre1(n, {0, 0});
        int cnt = 0, cnt1 = 0;
        bool bl = false;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                cnt = 0, cnt1 = 0;

            else
            {
                if (arr[i] > 0)
                {

                    cnt++;
                    bl = true;
                }
                else
                    cnt1++;
            }

            if (cnt1 % 2)
            {

                if (arr[i - (cnt + cnt1 - 1)] < 0)
                    pre[i] = {cnt, cnt1};

                else
                    pre[i] = {0, 0};
            }

            else
                pre[i] = {cnt, cnt1};
        }

        cnt = 0, cnt1 = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] == 0)
                cnt = 0, cnt1 = 0;
            else
            {
                if (arr[i] > 0)
                    cnt++;
                else
                    cnt1++;
            }

            if (cnt1 % 2)
            {
                if (arr[i + cnt + cnt1 - 1] < 0)
                    pre1[i] = {cnt, cnt1};
                else
                    pre1[i] = {0, 0};
            }
            else
                pre1[i] = {cnt, cnt1};
        }
        int mx = 0;
        if (bl)
            mx = 1;

        for (int i = 0; i < n - 1; i++)
        {

            int val = (pre[i].first + pre1[i + 1].first);

            int val1 = (pre[i].second + pre1[i + 1].second);

            if (val1 % 2)
                val1--;

            int res = (val + val1);
            mx = max(mx, res);
        }
        return mx;
    }
};


//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends