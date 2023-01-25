class Solution {
public:
    void dfs(int i, int dis, vector<int>& e, vector<int>& dist) {
        if (i!=-1 && dist[i]==-1) {
            dist[i] = dis;
            dfs(e[i], dis + 1, e, dist);
        }
    }
    
    int closestMeetingNode(vector<int>& e, int node1, int node2) {
        int res = -1, min_dist = INT_MAX;
        int n=e.size();
        
        vector<int> dist1(n,-1); 
        vector<int> dist2(n,-1);   
         
        dfs(node1, 0, e, dist1);
        dfs(node2, 0, e, dist2);
        
        for (int i = 0; i < n; i++){
            if (min(dist1[i], dist2[i]) >= 0 && max(dist1[i], dist2[i]) < min_dist) {
                min_dist = max(dist1[i], dist2[i]);
                res = i;
            }
        }  
        return res;
    }
};