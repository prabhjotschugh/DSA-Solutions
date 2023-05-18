class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res, visited(n);
        for (auto& e: edges)
            visited[e[1]] = 1;
        for (int i = 0; i < n; ++i)
            if (visited[i] == 0)
                res.push_back(i);

        return res;
    }
};