//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    
    bool binarysearch(vector<int>& nums,int s,int e,int target)
    {
        return binary_search(nums.begin(),nums.end(),target);            
    }
    
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int target) 
    {
        // code here 
        for(int i=0; i<n ; i++)
       {
           if(target>=matrix[i][0] && target <=matrix[i][m-1])
           {
               if(binarysearch(matrix[i],0,m-1,target))
                {
                    return true;
                }
           }
       }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends