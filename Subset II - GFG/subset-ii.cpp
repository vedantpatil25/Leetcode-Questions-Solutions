//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  void findSubset(int ind, vector<int>&nums, vector<int>&v, vector<vector<int>>&ans)
  {
        if(v.size() == 0) ans.push_back(v);
        if(ind == nums.size()) return;
        
        for(int i = ind ; i < nums.size() ; i++)
        {
            if(i > ind && nums[i] == nums[i-1]) continue;
            v.push_back(nums[i]);
            ans.push_back(v);
            findSubset(i+1, nums, v, ans);
            v.pop_back();
        }
        
  }
  
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        sort(nums.begin(), nums.end());
        vector<int>v;
        vector<vector<int>>ans;
        findSubset(0, nums, v, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends