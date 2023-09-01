//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      void findSubset(int ind, vector<int>&nums, vector<int>&v, vector<vector<int>>&ans)
  {
        if(v.size() == 0) ans.push_back(v);
        if(ind == nums.size()) return;
        
        for(int i = ind ; i < nums.size() ; i++)
        {
            v.push_back(nums[i]);
            ans.push_back(v);
            findSubset(i+1, nums, v, ans);
            v.pop_back();
        }
  }
    vector<vector<int> > subsets(vector<int>& nums){
        //code here
        vector<int>v;
        vector<vector<int>>ans;
        findSubset(0, nums, v, ans);
        sort(ans.begin(), ans.end());
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
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends