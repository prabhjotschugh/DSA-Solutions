class Solution {
public:
    int help(vector<vector<int>>&e,int k,int i,vector<vector<int>>&dp){
        if(i>=e.size())return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int ans = help(e,k,i+1,dp);
        if(k){
           vector<int> temp = {e[i][1],INT_MAX,INT_MAX};
           int in = upper_bound(e.begin(), e.end(), temp)-e.begin();
           ans = max(ans, e[i][2] + help(e,k-1,in,dp));
        }
        return dp[i][k] = ans;
    }
    int maxValue(vector<vector<int>>& e, int k) {
        sort(e.begin(),e.end());
        vector<vector<int>>dp(e.size(),vector<int>(k+1,-1));
        return help(e,k,0,dp);
    }
};