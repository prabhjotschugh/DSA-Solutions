class Solution {
public:
    bool help(int i,int k,vector<int>&s,vector<vector<int>>&dp){
        if(i==s.size()-1){
            return true;
        }
        bool a=false;
        if(dp[i][k]!=-1)return dp[i][k];
        for(int j=i+1;j<s.size();j++){
            if(s[j]>(s[i]+k+1))break;
            else if(s[j]==(s[i]+k-1)){
                a |= help(j,k-1,s,dp);
            }
            else if(s[j]==(s[i]+k)){
                 a |= help(j,k,s,dp);
            }
            else if(s[j]==(s[i]+k+1)){
                a |= help(j,k+1,s,dp);
            }
        }
        return dp[i][k]= a;
    }
    
    bool canCross(vector<int>& s) {
        vector<vector<int>>dp(s.size()+2,vector<int>(4000,-1));
        return help(0,0,s,dp);
    }
};