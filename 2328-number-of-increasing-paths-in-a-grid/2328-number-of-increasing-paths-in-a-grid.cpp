class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4] ={0,0,-1,1};
    long long mod=1e9+7;
    int n;int m;
    bool valid(int i,int j){
        if(i<0 || i>=n || j<0 || j>=m)return false;
        return true;
    }
    long long c(int i,int j,vector<vector<int>>& g,vector<vector<long long>>& dp){
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(valid(ni,nj) && g[i][j]<g[ni][nj]){
                ans  =  (ans%mod+ c(ni,nj,g,dp)%mod)%mod;
            }
        }
        dp[i][j]=ans;
        return ans%mod;
    }
    int countPaths(vector<vector<int>>& g) {
         n=g.size(),m=g[0].size();
        vector<vector<long long>>dp(n,vector<long long>(m,-1));
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = (ans%mod +c(i,j,g,dp)%mod)%mod;
            }
        }
        return ans;
    }
};