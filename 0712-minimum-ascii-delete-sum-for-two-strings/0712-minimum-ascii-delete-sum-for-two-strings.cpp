class Solution {
public:
    long long help(int i,int j,string& s1,string &s2,vector<vector<int>>&dp){
        if(i==s1.size() && j==s2.size())return 0;
        if(i==s1.size()){
            int d=0;
            for(int k=j;k<s2.size();k++){
                d += (int)s2[k];
            }
            return d;
        }
        if(j==s2.size()){
            int d=0;
            for(int k=i;k<s1.size();k++){
                d += (int)s1[k];
            }
            return d;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        long long ans = INT_MAX;
        if(s1[i]==s2[j])ans = help(i+1,j+1,s1,s2,dp);
        else {
            ans = min(ans, s1[i] + help(i+1,j,s1,s2,dp));
            ans = min(ans, s2[j] + help(i,j+1,s1,s2,dp));
        }
        return dp[i][j] = ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));
        return help(0,0,s1,s2,dp);
    }
};