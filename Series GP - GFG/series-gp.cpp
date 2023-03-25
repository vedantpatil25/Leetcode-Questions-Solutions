//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
 long long int power(int r, int n){
     int m=1000000007;
           if(n==0) return 1;
          long long int temp = power(r,n/2)%m;
           temp=(temp*temp)%m;
           if(n%2==0) return temp;
           else return (temp*r)%m;
       }


   int Nth_term(int a, int r, int n){
       int m=1000000007;
       int x=(a*power(r,n-1))%m;
       return x;
     
   }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, r, n;
		cin >> a >> r >> n;
		Solution ob;
		int ans = ob.Nth_term(a, r, n);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends