class Solution {
public:
    int diameter(vector<vector<int>>& edges) {
        int m = edges.size() + 1, res = 0; 
        vector<vector<int>> al(m);
        vector<int> degree(m), depth(m), vis(m);    
        queue<int> q;    
        for (const auto &e : edges) {
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < m; ++i)
            if ((degree[i] = al[i].size()) == 1)
                q.push(i);
        while (!q.empty()) {
            int i = q.front(); q.pop();
            vis[i] = true;
            for (int j : al[i]) {
                if (--degree[j] == 1)
                    q.push(j);
                if (!vis[j]) {                        
                    res = max(res, depth[j] + depth[i] + 1);
                    depth[j] = max(depth[j], depth[i] + 1);
                }
            }
        }
        return res;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        auto d1 = diameter(e1), d2 = diameter(e2);
        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};