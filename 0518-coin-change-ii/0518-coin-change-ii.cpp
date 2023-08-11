class Solution {
public:
    #define ll long long int
    int change(int sum, vector<int>& coins) {
        int n = coins.size();
        ll dp[n+1][sum+1];
        for(ll i=0;i<n+1;i++){
            for(ll j=0;j<sum+1;j++){
                if(i==0) dp[i][j] = 0;
                if(j==0) dp[i][j] = 1;
            }
        }
        
        for(ll i=1;i<n+1;i++){
            for(ll j=0;j<sum+1;j++){
                if(coins[i-1] <= j){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};