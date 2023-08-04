class Solution {
public:
    map<string,int>m;
    bool help(int i,string &s,vector<int>&dp){
        if(i==s.size())return true;
        if(dp[i]!=-1)return dp[i];
        bool ans = false;
        string a = "";
        for(int k=i;k<s.size();k++){
            a += s[k];
            if(m[a]){
                ans |= help(k+1,s,dp);
            }
        }
        return  dp[i] = ans;
    }
    bool wordBreak(string s, vector<string>& w) {
        for(auto i:w){
            m[i]++;
        }
        vector<int>dp(s.size(),-1);
        return help(0,s,dp);
    }
};