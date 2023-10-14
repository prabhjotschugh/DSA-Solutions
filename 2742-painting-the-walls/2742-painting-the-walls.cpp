class Solution {
public:
    int helper(int ind, int total, vector<int>&cost, vector<int>&time, vector<vector<int>>&dp){
        if(total <=0) 
            return 0;
        if(ind>= cost.size()) 
            return 1e9; 
        if(dp[ind][total] != -1) 
            return dp[ind][total];

        int take = cost[ind] + helper(ind+1 , total-time[ind]-1 , cost,time,dp);
        int notTake =  0 + helper(ind+1 , total, cost,time,dp);
        return dp[ind][total] = min(take,notTake);
    }

    int paintWalls(vector<int>& cost, vector<int>& time){
        int n = cost.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(0,cost.size() , cost,time,dp);
    }
};