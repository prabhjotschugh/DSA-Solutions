class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (mat[i][j]==0) {
                    q.push({i, j});
                    dp[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto [i, j]=q.front();
            q.pop();
            int d=dp[i][j];
            vector<pair<int, int>> adj={{i, j+1}, {i+1, j}, {i, j-1}, {i-1, j}};
            for(auto [a, b]: adj){
                if (a<0 || a>=n || b<0 || b>=m || dp[a][b]!=-1) continue;
                q.push({a, b});
                dp[a][b]=d+1;
            }
        }
        return dp;
    }
};