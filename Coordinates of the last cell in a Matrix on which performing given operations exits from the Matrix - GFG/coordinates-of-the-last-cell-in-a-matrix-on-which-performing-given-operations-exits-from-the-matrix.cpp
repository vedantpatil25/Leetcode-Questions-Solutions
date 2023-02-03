//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    pair<int, int> endPoints(vector<vector<int>> matrix)
    {
        int i = 0;
        int j = 0;
        
        string dir = "right";
        int n = matrix.size();
        int m = matrix[0].size();
        
        while (i >= 0 && i < n && j >= 0 && j < m)
        {
            if (matrix[i][j] == 0 && dir == "right")
            {
                j++;
            }
            else if (matrix[i][j] == 0 && dir == "left")
            {
                j--;
            }
            else if (matrix[i][j] == 0 && dir == "up")
            {
                i--;
            }
            else if (matrix[i][j] == 0 && dir == "down")
            {
                i++;
            }
            else if (matrix[i][j] == 1 && dir == "up")
            {
                matrix[i][j] = 0;
                j++;
                dir = "right";
            }
            else if (matrix[i][j] == 1 && dir == "right")
            {
                matrix[i][j] = 0;
                i++;
                dir = "down";
            }
            else if (matrix[i][j] == 1 && dir == "down")
            {
                matrix[i][j] = 0;
                j--;
                dir = "left";
            }
            else
            {
                matrix[i][j] = 0;
                i--;
                dir = "up";
            }
        }

        if (i < 0)
        {
            return {i + 1, j};
        }
        else if (j < 0)
        {
            return {i, j + 1};
        }
        else if (i >= n)
        {
            return {n - 1, j};
        }
        else
        {
            return {i, m - 1};
        }
    }
};


//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends