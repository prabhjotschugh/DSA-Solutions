class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for(auto& e : edges) {
            indegree[e[0]]++, indegree[e[1]]++;
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (indegree[i] >= 2) continue;
            visited[i] = true;
            leaves.push(i);
        }
        
        vector<int> result;
        while (!leaves.empty()) {
            int size = leaves.size();
            result.clear();
            for (int i = 0; i < size; i++) {
                int curr = leaves.front();
                leaves.pop();
                result.push_back(curr);
                for (auto& next : graph[curr]) {
                    if (visited[next]) continue;
                    if ((--indegree[next]) == 1) {
                        visited[next] = true;
                        leaves.push(next);
                    }
                }
            }
        }
        return result;
    }
};