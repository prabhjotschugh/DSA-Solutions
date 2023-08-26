class Solution {
public:
    int help(int i,vector<vector<int>>&pairs,int mx,vector<vector<int>>&dp){
        if(i==pairs.size())return 0;
        if(dp[i][mx+1001]!=-1)return dp[i][mx+1001];
        int ans = help(i+1,pairs,mx,dp);
        if(pairs[i][0]>mx){
            ans = max(ans,1+help(i+1,pairs,pairs[i][1],dp));
        }
        return  dp[i][mx+1001]=ans;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(pairs.size(),vector<int>(2010,-1));
        return help(0,pairs,-1001,dp);       
    }
};