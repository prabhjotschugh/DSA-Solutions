class Solution {
public:
    vector<int> topologicalSort(vector<vector<int>>& graph, vector<int>& degrees) {
        vector<int> sorted;
        queue<int> q;
        for (int i = 0; i < degrees.size(); ++i) {
            if (degrees[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            sorted.push_back(u);
            for (int v : graph[u]) {
                degrees[v]--;
                if (degrees[v] == 0) {
                    q.push(v);
                }
            }
        }
        return sorted.size() == graph.size() ? sorted : vector<int>();
    };
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int u = 0; u < n; ++u) {
            if (group[u] == -1) {
                group[u] = m++;
            }
        }

        vector<vector<int>> graph(n), groupGraph(m);

        vector<int> degrees(n, 0), groupDegree(m, 0);

        for (int u = 0; u < n; ++u) {
            for (int v : beforeItems[u]) {
                graph[v].push_back(u);
                degrees[u]++;
                if (group[u] != group[v]) {
                    groupGraph[group[v]].push_back(group[u]);
                    groupDegree[group[u]]++;
                }
            }
        }
        vector<int> itemsSorted = topologicalSort(graph, degrees);
        vector<int> groupsSorted = topologicalSort(groupGraph, groupDegree);

        if (itemsSorted.empty() || groupsSorted.empty()) {
            return {};
        }

        vector<int> order;
        unordered_map<int, vector<int>> groupItems;

        for (int v : itemsSorted) {
            groupItems[group[v]].push_back(v);
        }

        for (int group : groupsSorted) {
            for (int item : groupItems[group]) {
                order.push_back(item);
            }
        }

        return order;
    }
};
