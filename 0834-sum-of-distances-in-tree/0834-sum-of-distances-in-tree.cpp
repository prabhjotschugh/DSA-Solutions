class Solution {
public:
    void dfs(vector<int> adj[],int n,int node,int prev,vector<int> &height,vector<int> &subtree){
        subtree[node]++;
        for(auto &ele:adj[node]){
            if(ele!=prev){
                height[ele] = 1 + height[node];
                dfs(adj,n,ele,node,height,subtree);
                subtree[node] += subtree[ele];
            }
        }
    }
    void rec(vector<int> adj[],int n,int node,int prev,vector<int> &subtree,vector<int> &dp){
        for(auto &ele:adj[node]){
            if(ele!=prev){
                dp[ele] = dp[node] - subtree[ele] + (n-subtree[ele]);
                rec(adj,n,ele,node,subtree,dp);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges){
        vector<int> adj[n];
        for(auto &ele:edges){
            int u = ele[0], v = ele[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> height(n,0),subtree(n,0); 
        vector<int> dp(n,0);
        dfs(adj,n,0,-1,height,subtree);
        for(int i=0;i<n;i++) dp[0] += height[i];
        rec(adj,n,0,-1,subtree,dp);
        return dp;
    }
};