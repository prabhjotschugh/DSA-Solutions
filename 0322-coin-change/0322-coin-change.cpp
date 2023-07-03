class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for(int i=0;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i >= coins[j]){
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                }
            }
        }
        return (dp[amount] == INT_MAX-1) ? -1 : dp[amount];
    }
};