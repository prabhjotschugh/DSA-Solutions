class DSU{
    private:
        const int N = 1e6+10;
        vector<int> parent, size, rank;
    public:
        DSU(){
            parent.resize(N);
            iota(begin(parent),end(parent),0);
            size.resize(N,1);
            rank.resize(N,0);
        }
        DSU(int n){
            parent.resize(n+1);
            iota(begin(parent),end(parent),0);
            size.resize(n+1,1);
            rank.resize(n+1,0);
        }
        int find(int v){
            if(parent[v] == v) return v;
            //path compression
            return parent[v] = find(parent[v]);
        }
        // custom merging
        void merge(){
         
        }
        int getsize(int n){
         return size[n];
        }
        void unionS(int a,int b){
            a = find(a);
            b = find(b);
            if(a!=b){
                //union by size
                if(size[a] < size[b]) swap(a,b);
                parent[b] = a;
                size[a] += size[b];
            }
        }
        void unionR(int x, int y) {
            x = find(x), y = find(y);
            if(x == y) return;
            //union by rank
            else if(rank[x] < rank[y]) parent[x] = y;
            else if (rank[x] > rank[y]) parent[y] = x;
            else parent[y] = x,rank[x]++;
      }
};
class Solution {
private:
    int mstsum = 0;
    int kruskal(vector<vector<int>>&edges,int n,pair<pair<int,int>,int> include,int ignore=-1){
        DSU ds(n);
        int mst = 0;
        if(include.second != -1){
            ds.unionS(include.first.first,include.first.second);
            mst += include.second;
        }
        for(auto&e: edges){
            int u = e[0], v = e[1], wt = e[2], id = e[3];
            if(id == ignore) continue;
            if(ds.find(u) != ds.find(v)){
                mst += wt;
                ds.unionS(u,v);
            }
        }
        if(mst < mstsum) return 1e9;
        return mst;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = size(edges);
        for(int i=0; i<m; ++i) edges[i].push_back(i);
        sort(begin(edges),end(edges),[](auto&a,auto&b){return a[2] < b[2];});

        vector<int> critical, pseudocritical;
        unordered_set<int> critcalset;
 
        int mst = kruskal(edges,n,{{-1,-1},-1});
        mstsum = mst;

        for(auto&e: edges){
            int x = kruskal(edges,n,{{-1,-1},-1},e[3]);
            if(x > mst){
                critical.push_back(e[3]);
                critcalset.insert(e[3]);
            }
        }

        for(auto&e: edges){
            pair<pair<int,int>,int> p = {{e[0],e[1]},e[2]};
            int x = kruskal(edges,n,p);
            if(x == mst && !critcalset.count(e[3])) pseudocritical.push_back(e[3]);
        }

        return {critical,pseudocritical};
    }
};