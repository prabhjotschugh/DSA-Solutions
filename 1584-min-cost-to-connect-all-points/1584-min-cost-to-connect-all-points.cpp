class Solution {
public:
    vector<int> par;
    vector<int> sz;
    
    int find_par ( int u ) {
        if ( u == par[u] ) return u;
        return par[u] = find_par ( par[u] );
    }
    
    void Union ( int u, int v ) {
        if ( sz[u] < sz[v] ) swap ( u, v );
        par[v] = u;
        sz[u] += sz[v];
    }
    
    int calcDist ( vector<int> p1, vector<int> p2 ) {
        return abs ( p1[0] - p2[0] ) + abs ( p1[1] - p2[1] );
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        par.clear();
        sz.clear();
        int n = points.size();
        par.resize( n );
        sz.resize( n );
        for ( int i = 0; i < n; i++ ) par[i] = i;
        vector<pair<int, pair<int, int>>> edges;
        for ( int i = 0; i < n; i++ ) {
            for ( int j = i+1; j < n; j++ ) {
                int w = calcDist ( points[i], points[j] );
                edges.push_back ( {w, { i, j }} );
            }
        }
        sort ( edges.begin(), edges.end() );
        int ans = 0;
        int cnt = 0;
        for ( auto e : edges ) {
            int u = e.second.first;
            int v = e.second.second;
            int w = e.first;
            u = find_par(u);
            v = find_par(v);
            if ( u != v ) {
                Union( u, v );
                cnt++;
                ans += w;
                
                if ( cnt == n-1 ) {
                    break;
                }
            }
        }
        return ans;
    }
};