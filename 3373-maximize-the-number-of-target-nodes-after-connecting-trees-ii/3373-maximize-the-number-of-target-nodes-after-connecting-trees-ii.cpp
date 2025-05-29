class Solution {
public:
    vector<vector<int>> tree1, tree2;
    vector<int> color1, color2;
    vector<int> nodeColor1, nodeColor2;
    void build(vector<vector<int>> &edges, vector<vector<int>> &mp) {
        mp.resize(edges.size() + 1);
        for(auto &e : edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
    }
    void bfs(vector<vector<int>> &mp, vector<int> &color, vector<int> &nodeColor) {
        int n = mp.size();
        queue<pair<int, int>> q;
        vector<bool> vis(n, 0);
        q.push({0, 0});
        while(!q.empty()) {
            auto[i, c] = q.front(); q.pop();
            vis[i] = true;
            nodeColor[i] = c;
            color[c]++;
            for(int adj : mp[i]) if(!vis[adj]) {
                q.push({adj, (c + 1) % 2});
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        nodeColor1.assign(n, 0); nodeColor2.assign(m, 0);
        color1.assign(2, 0); color2.assign(2, 0);
        build(edges1, tree1);
        build(edges2, tree2);
        bfs(tree1, color1, nodeColor1);
        bfs(tree2, color2, nodeColor2);
        vector<int> arr(n);
        int mx = max(color2[0], color2[1]);
        for(int i = 0; i < n; i++) arr[i] = color1[nodeColor1[i]] + mx;
        return arr;
    }
};