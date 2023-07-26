//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int subsetSum(vector<int>& arr, int n, int sum){
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        dp[0][0] = 1;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>&arr ,int target) {
        //Your code here
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        
        if((sum + target)%2 != 0){
            return 0;
        }
        int targetSum = (sum + target)/2;
        return subsetSum(arr, n, targetSum);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends