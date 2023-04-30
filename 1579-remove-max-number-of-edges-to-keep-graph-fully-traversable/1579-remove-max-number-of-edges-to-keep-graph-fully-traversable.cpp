class DSU {
public:
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n, 0);
        rank.resize(n, 0);
        
        for(int i=0;i<n;i++) parent[i] = i;
    }
    
    int Find(int x){
        return parent[x] = parent[x] == x ? x : Find(parent[x]);
    }
    
    bool Union(int x, int y){
        int xset = Find(x), yset = Find(y);
        if(xset != yset){
            rank[xset] < rank[yset] ? parent[xset] = yset : parent[yset] = xset;
            rank[xset] += rank[xset] == rank[yset];
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [&](auto const &a, auto const &b){
            return a[0] > b[0];
        });

        DSU dsu_alice(n+1);
        DSU dsu_bob(n+1);

        int removed_edge = 0, alice_edges=0, bob_edges=0;
        for(auto edge : edges){
            if(edge[0] == 3){
                if(dsu_alice.Union(edge[1], edge[2])){ // Both Alice & Bob
                    dsu_bob.Union(edge[1], edge[2]);
                    alice_edges++;
                    bob_edges++;
                }else{
                    removed_edge++;
                }
            }else if(edge[0] == 2){ //Only Bob
                if(dsu_bob.Union(edge[1], edge[2])){
                    bob_edges++;
                }else{
                    removed_edge++;
                }
            }else{ // Only Alice
                if(dsu_alice.Union(edge[1], edge[2])){
                    alice_edges++;
                }else{
                    removed_edge++;
                }
            }
        }

        return (bob_edges == n - 1 && alice_edges == n - 1) ? removed_edge : -1;
    }
};
