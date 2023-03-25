//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int n = nums.size();
        int xorr = 0;
        for(auto x:nums) xorr^=x;
        int setbitpos = 0;
        
        while(xorr)
        {
            if(xorr&1) break;
            setbitpos++;
            xorr = xorr>>1;
        }
        
        int num1 = 0;
        int num2 = 0;

        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] & (1 << setbitpos) ) num1 ^= nums[i];
            else num2 ^= nums[i];
        }
        if(num1 > num2)
        {
            return  {num2, num1};
        }
        return {num1, num2} ;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends