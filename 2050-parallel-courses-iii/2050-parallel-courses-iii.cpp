class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for (const vector<int>& r : relations) {
            const int& prevCourse = r[0] - 1;
            const int& nextCourse = r[1] - 1;
            graph[prevCourse].push_back(nextCourse);
            indegree[nextCourse]++;
        }

        queue<int> q;
        vector<int> minTime(n, 0);
        for (int i = 0; i < n; i++) {
            if (indegree[i] != 0) continue;
            q.push(i);
            minTime[i] = time[i];
        }

        while (!q.empty()) {
            const int& curr = q.front();
            for (const int& next : graph[curr]) {
                minTime[next] = max(minTime[next], minTime[curr] + time[next]);
                if ((--indegree[next]) == 0) q.push(next);
            }
            q.pop();
        }

        return *(max_element(minTime.begin(), minTime.end()));  
    }
};