class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> dis(n,0);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(auto &x:graph[i]){
                adj[x].push_back(i);
                dis[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(dis[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto x:adj[node]){
                dis[x]--;
                if(dis[x]==0){
                    q.push(x);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};