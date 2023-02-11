class Solution {
public:
    void bfs(int n,vector<pair<int,int>> adj[],vector<int> &dp){
        queue<vector<int>> q;
        q.push({0,0,0});
        q.push({0,0,1});
        vector<vector<int>> vis(n,vector<int>(2,0));
        vis[0][0]=1;
        vis[0][1]=1;
        while(!q.empty()){
            auto curr=q.front();q.pop();
            int d=curr[0],node=curr[1],c1=curr[2];
            for(auto x:adj[node]){
                int child=x.first,c2=x.second;
                if(c2!=c1){
                    dp[child]=min(dp[child],1+d);
                    if(vis[child][c2]==0) q.push({1+d,child,c2});
                    vis[child][c2]=1;
                }
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& R, vector<vector<int>>& B) {
        vector<pair<int,int>> adj[n];
        for(auto x:R){
            adj[x[0]].push_back({x[1],1});
        }
        for(auto x:B){
            adj[x[0]].push_back({x[1],0});
        }
        vector<int> dp(n,INT_MAX-1);
        dp[0]=0;
        bfs(n,adj,dp);
        for(int i=0;i<n;i++){
            if(dp[i]>=INT_MAX-1) dp[i]=-1;
        }
        return dp;
    }
};