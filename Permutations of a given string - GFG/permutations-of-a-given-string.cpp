//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(int ind, string &S, set<string>&st){
	        if(ind == S.size() ){
	            st.insert(S);
	        }
	        for(int i = ind ; i < S.size() ; i++){
	            swap(S[i], S[ind]);
	            solve(ind+1, S, st);
	            swap(S[i], S[ind]);
	        }
	        
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string>st;
		    solve(0, S, st);
		    vector<string>ans(st.begin(), st.end());
		    sort(ans.begin(), ans.end());
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
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends