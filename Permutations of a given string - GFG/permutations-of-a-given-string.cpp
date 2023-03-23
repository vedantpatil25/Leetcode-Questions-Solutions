//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(string S, int ind , set<string>&temp)
	    {
	        if(ind == S.size())
	        {
	            temp.insert(S);
	            return;
	        }
	        
	        for(int i = ind ; i < S.size(); i++)
	        {
	            swap(S[ind], S[i]);
	            solve(S, ind+1, temp);
	            swap(S[ind], S[i]);
	        }
	    }
	
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string>temp;
		    solve(S, 0, temp);
		    
		    vector<string>ans(temp.begin(), temp.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends