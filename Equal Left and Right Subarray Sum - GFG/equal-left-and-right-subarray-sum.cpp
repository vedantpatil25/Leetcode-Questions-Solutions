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
    int equalSum(int N, vector<int> &A) {
        // code here
        int l = 0, r = N-1;
        int ls = 0, rs = 0;
        while(l<r){
            if(ls == rs){
                ls += A[l++];
                rs += A[r--];
            }else if(ls<rs)ls+=A[l++];
            else rs += A[r--];
            // cout<<"ls: "<<ls<<" rs: "<<rs<<"\n";
        }
        if(ls == rs && l<=r)return l+1;
        else return -1;
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
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends