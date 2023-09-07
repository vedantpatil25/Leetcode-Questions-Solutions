//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    
    bool isPossible(int grid[N][N], int curr_row,int curr_col,int val){
        for(int i= 0; i < N; i++){
            if(grid[curr_row][i] == val)return false; 
            if(grid[i][curr_col] == val)return false; 
        }
        
        for(int i = 0;i< N; i++){
            if(grid[3*(curr_row/3)+i/3][3*(curr_col/3)+i%3] == val)return false; 
        }
        
        return true; 
    }
    
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // to find the empty place
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                
                //found empty place
                if(grid[i][j] == 0){
                    
                    // trying all the possible solu from 1 -> 9 on empty space 
                    for(int k = 0 ; k < 10 ; k++){
                        
                        // check if we can put k at the empty place 
                        if(isPossible(grid, i, j, k) == true){
                            
                            grid[i][j] = k;
                            
                            if(SolveSudoku(grid) == true){
                                return true;
                            }
                            grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                cout<< grid[i][j] << " ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends