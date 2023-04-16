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
    long long solve(int N, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        vector<long long>Ao, Ae, Bo, Be;
        long long sum = 0;
        for(int i = 0 ; i < A.size() ; i++)
        {
            if((A[i]&1) == 1) Ao.push_back(A[i]);
            else Ae.push_back(A[i]);
            
            if((B[i]&1) == 1) Bo.push_back(B[i]);
            else Be.push_back(B[i]);
            
            sum += A[i];
            sum -= B[i];
        }
        
        // cout<<sum<<" "<<Ao.size()<<" "<<Bo.size()<<" "<<Ae.size()<<" "<<Be.size()<<endl;
        if(sum != 0 || Ao.size() != Bo.size() || Ae.size() != Be.size()) return -1;
        
        long long ans = 0;
        for(int i = 0 ; i < Ao.size() ; i++)
        {
            ans += abs(Ao[i] - Bo[i]);
        }
        for(int i = 0 ; i < Ae.size() ; i++)
        {
            ans += abs(Ae[i] - Be[i]);
        }
        return (ans/4);
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
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends