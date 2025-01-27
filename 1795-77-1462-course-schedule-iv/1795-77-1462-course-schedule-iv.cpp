class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto p : prerequisites) {
            adj[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        unordered_map<int, unordered_set<int>> mp;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto next : adj[curr]) {
                mp[next].insert(curr);
                for(auto pre : mp[curr]) {
                    mp[next].insert(pre);
                }
                indegree[next]--;
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        vector<bool> res;
        for(auto q : queries) {
            res.push_back(mp[q[1]].count(q[0]));
        }
        return res;
    }
};