//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       // Remove leading zeros
    int i = 0;
    while (i < s1.size() && s1[i] == '0') i++;
    s1 = s1.substr(i);
    i = 0;
    while (i < s2.size() && s2[i] == '0') i++;
    s2 = s2.substr(i);
    
    // Check for negative numbers
    bool negative = false;
    if (s1[0] == '-') {
        negative = !negative;
        s1 = s1.substr(1);
    }
    if (s2[0] == '-') {
        negative = !negative;
        s2 = s2.substr(1);
    }
    
    // Initialize result
    vector<int> result(s1.size() + s2.size(), 0);
    
    // Multiply each digit of the first number with each digit of the second number
    for (int i = s1.size()-1; i >= 0; i--) {
        int carry = 0;
        for (int j = s2.size()-1; j >= 0; j--) {
            int temp = (s1[i] - '0') * (s2[j] - '0') + carry + result[i+j+1];
            carry = temp / 10;
            result[i+j+1] = temp % 10;
        }
        
        // Add remaining carry to the next position
        result[i] += carry;
    }
    
    // Convert result to string and remove leading zeros
    string result_str;
    for (int x : result) result_str.push_back(x + '0');
    i = 0;
    while (i < result_str.size() && result_str[i] == '0') i++;
    result_str = result_str.substr(i);
    
    // Add negative sign if necessary
    if (negative) {
        result_str.insert(result_str.begin(), '-');
    }
    
    return result_str.empty() ? "0" : result_str;
}
};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends