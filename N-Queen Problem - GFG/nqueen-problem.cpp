//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool isSafe(int i, int j, vector<vector<int>> &board, int n){
        for(int k = 0 ; k < n ; k++){
            if(board[i][k] == 1) return false;
            if(board[k][j] == 1) return false;
            if(i-k >= 0 && j-k >= 0){
                if(board[i-k][j-k] == 1) return false;
            }
            
            if(i+k < n && j+k < n){
                if(board[i+k][j+k] == 1) return false;
            }
            if(i+k < n && j-k >= 0){
                if(board[i+k][j-k] == 1) return false;
            }
            if(i-k >= 0 && j+k < n){
                if(board[i-k][j+k] == 1) return false;
            }
        }
        return true;
    }
    void solve(int n, vector<vector<int>> &ans, vector<int>path, int row,vector<vector<int>> &board){
        
        if(row == n){
            ans.push_back(path);
            return;
        }
        for(int j = 0 ; j < n ; j++){
            if(isSafe(row, j, board, n)){
                board[row][j] = 1;
                path.push_back(j+1);
                solve(n, ans, path,row+1,board);
                path.pop_back();
                board[row][j] = -1;
            }
        }

    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n,vector<int>(n,-1));
        vector<int> path;
        vector<vector<int>> ans;
        solve(n, ans, path, 0, board);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends