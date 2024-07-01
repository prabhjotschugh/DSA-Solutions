class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n);
        for(auto &i: edges)
        {
            adj[i[0]].push_back(i[1]);
        }
        for(int par=0;par<n;par++)
        {
            queue<int> q;
            q.push(par);
            while(!q.empty())
            {
                int f=q.front();
                q.pop();
                for(auto &child:adj[f])
                {
                    if(ans[child].size()==0||ans[child].back()!=par){
                        ans[child].push_back(par);
                        q.push(child);
                    }
                }
            }
        }
        return ans;
    }
};