class Solution {
public:
    int ans=1;
    void solve(vector<vector<int>> &graph,int i,vector<int> &vis,vector<int> &color,int flag){
        vis[i]=1;
        for(auto itr : graph[i]){
            if(vis[itr] == 0)
            {
                color[itr]=!flag;
                solve(graph,itr,vis,color,!flag);
            }
            if(vis[itr]==1){
                if(color[itr]==flag){
                    ans=0;
                    break;
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> color(n,-1);
        int flag=0;
        color[0]=0;
        int count=0;
        for(int i=0; i<n; i++){
            if(vis[i]==0)
                solve(graph,i,vis,color,flag);
        }
        
        if(ans==0)
            return false;
        return true;
    }
};