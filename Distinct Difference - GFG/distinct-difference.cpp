//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        vector<int>left(N);
        vector<int>right(N);
        vector<int>ans(N);
        // left[0] = 0;
        set<int>s1;
        set<int>s2;
        
        for(int i = 0; i< N; i++)
        {
            left[i] = s1.size();
            right[N-i-1] = s2.size();
            
            s1.insert(A[i]);
            s2.insert(A[N-i-1]);
        }
        for(int i = 0; i< N; i++)
        {
            ans[i] = left[i]-right[i];
        }
        // cout<<"temp  "<<left[N-1]<<" "<<right[N-1]<<endl;

        return ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends