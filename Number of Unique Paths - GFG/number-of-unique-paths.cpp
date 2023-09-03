//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int solve(int m, int n, vector<vector<int>>& dp){
        if(m==0 && n==0){
            return 1;
        }
        
        if(m<0 || n<0){
            return 0;
        }
        
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        
        int upPaths = solve(m-1, n, dp);
        int leftPaths = solve(m, n-1, dp);
        
        return dp[m][n] = upPaths + leftPaths;
    }
    int NumberOfPath(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends