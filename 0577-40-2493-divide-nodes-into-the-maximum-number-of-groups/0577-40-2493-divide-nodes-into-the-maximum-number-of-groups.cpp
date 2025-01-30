#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // Step 1: Create adjacency list
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, 0); // 0 = unvisited, 1 = color1, -1 = color2
        vector<int> component(n + 1, -1);
        int componentId = 0;
        
        // Step 2: Check for bipartiteness and group connected components
        function<bool(int, int)> isBipartite = [&](int node, int compId) {
            queue<int> q;
            q.push(node);
            color[node] = 1;
            component[node] = compId;
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                
                for (int neighbor : adj[curr]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[curr]; // Assign opposite color
                        component[neighbor] = compId;
                        q.push(neighbor);
                    } else if (color[neighbor] == color[curr]) {
                        return false; // Not bipartite
                    }
                }
            }
            return true;
        };

        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0) {
                if (!isBipartite(i, componentId++)) {
                    return -1; // Graph contains an odd cycle
                }
            }
        }

        // Step 3: Compute max BFS depth in each component
        auto maxBFS = [&](int start) -> int {
            queue<int> q;
            unordered_map<int, int> dist;
            q.push(start);
            dist[start] = 1;
            int maxDepth = 1;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : adj[node]) {
                    if (!dist.count(neighbor)) {
                        dist[neighbor] = dist[node] + 1;
                        maxDepth = max(maxDepth, dist[neighbor]);
                        q.push(neighbor);
                    }
                }
            }
            return maxDepth;
        };

        unordered_map<int, vector<int>> components;
        for (int i = 1; i <= n; ++i) {
            components[component[i]].push_back(i);
        }

        int maxGroups = 0;
        for (const auto& [compId, nodes] : components) {
            int best = 0;
            for (int node : nodes) {
                best = max(best, maxBFS(node));
            }
            maxGroups += best;
        }

        return maxGroups;
    }
};