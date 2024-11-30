class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        unordered_map<int, stack<int>> g;
        unordered_map<int, int>in, out;
        g.reserve(n), in.reserve(n), out.reserve(n);
        
        for (auto& p : pairs) {
            in[p[1]]++;
            out[p[0]]++;
            g[p[0]].push(p[1]);
        }
        int start = -1, fst;
        for (auto& p: g) {
            fst = p.first;
            if (out[fst] - in[fst] == 1) 
                start = fst;
        }
        if (start == -1) {
            start = fst;
        }

        vector<vector<int>> result;
        dfs(g, start, result);
        reverse(result.begin(), result.end());

        return result;
    }
    void dfs(unordered_map<int, stack<int>>& g, int node, vector<vector<int>>& res) {
        while (!g[node].empty()) {
            int next = g[node].top();
            g[node].pop();
            dfs(g, next, res);
            res.push_back({node, next});
        }
    }
};