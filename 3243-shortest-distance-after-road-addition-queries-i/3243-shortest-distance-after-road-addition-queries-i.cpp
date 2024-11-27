class Solution {
void updateDistances(vector<vector<int>>& graph, int current, vector<int>& distances) {
        int newDist = distances[current] + 1;
        for (int neighbor : graph[current]) {
            if (distances[neighbor] <= newDist) continue;
            distances[neighbor] = newDist;
            updateDistances(graph, neighbor, distances);
        }
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> distances(n);
        for (int i = 0; i < n; ++i) {
            distances[i] = n - 1 - i;
        }
        
        vector<vector<int>> graph(n);
        for (int i = 0; i + 1 < n; ++i) {
            graph[i + 1].push_back(i);
        }
        
        vector<int> answer(queries.size());
        int queryIdx = 0;
        
        for (const auto& query : queries) {
            int source = query[0];
            int target = query[1];
            
            graph[target].push_back(source);
            distances[source] = min(distances[source], distances[target] + 1);
            updateDistances(graph, source, distances);
            
            answer[queryIdx++] = distances[0];
        }
        
        return answer;
    }
};