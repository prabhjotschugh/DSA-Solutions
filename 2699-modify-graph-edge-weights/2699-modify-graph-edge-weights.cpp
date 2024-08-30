class Solution {
public:
    const int INF = 2e9;
    int dijkstra(int n, int src, int dest, vector<pair<int,int>>adj[]){
        vector<int>dist(n,1e9);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto [dis, node] = pq.top(); pq.pop();
            if(node == dest) break;
            for(auto it : adj[node]){
                int neighdist = it.second, neighnode=it.first;
                if(dis+neighdist < dist[neighnode]){
                    dist[neighnode] = dis+neighdist;
                    pq.push({dist[neighnode], neighnode});
                }
            }
        }
        return dist[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
        vector<pair<int,int>>adj[n];
        for(auto it : edges){
            int u=it[0], v=it[1], wt=it[2];
            if(wt == -1) continue;
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        int shortestpath = dijkstra(n,src,dest,adj);
        if(shortestpath < target) return {};
        bool isequal = (shortestpath == target);
        for(auto &it : edges){
            // int u=it[0], v=it[1], wt=it[2];
            if(it[2] != -1) continue;

            it[2] = isequal ? INF : 1;
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});

            if(!isequal){
                int newshortestpath =  dijkstra(n,src,dest,adj);
                if(newshortestpath <= target){
                    isequal = true;
                    it[2] += target-newshortestpath;
                }
            }
        }
        if(isequal) return edges;
        return {};
    }
};