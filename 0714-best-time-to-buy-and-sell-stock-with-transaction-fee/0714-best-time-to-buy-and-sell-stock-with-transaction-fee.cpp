class Solution {
public:
    int c(int buy,vector<int>&price,int fee,int i,vector<vector<int>>&dp){
        if(i>=price.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int not_take = c(buy,price,fee,i+1,dp);
        int take=0;
        if(buy){
            take = c(1-buy,price,fee,i+1,dp) - price[i] - fee;
        }
        else {
            take = price[i] + c(1-buy,price,fee,i+1,dp);
        }
       return dp[i][buy]= max(take,not_take);
    }
    int maxProfit(vector<int>& price, int fee) {
        vector<vector<int>>dp(price.size(),vector<int>(2,-1));
        return c(1,price,fee,0,dp);
    }
};
