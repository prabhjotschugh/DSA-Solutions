class Solution {

private:
    bool isValid(int r, int c, int n){
        if(r>=n || c>=n || r<0 || c<0) return false;
        return true;
    }

public:

    class Ds{
        public:
            vector<int> par,size;
            Ds(int n){
                for(int i=0;i<=n;i++) par.push_back(i);
                size.resize(n+1,1);
            }
            int upar(int a){
                if(a==par[a]) return a;
                return par[a] = upar(par[a]);
            }
            void unionS(int a, int b){
                int ap = upar(a), bp = upar(b);
                if(ap==bp) return;
                int as = size[ap], bs = size[bp];
                if(as<bs){
                    par[ap] = bp;
                    size[bp]+=as;
                } else{
                    par[bp] = ap;
                    size[ap]+=bs;
                }
            }
    };

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Ds ds(n*n);
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int node = i*n + j;
                if(grid[i][j]==1){
                    for(int ind=0;ind<4;ind++){
                        int newx = i + dx[ind];
                        int newy = j + dy[ind];
                        if(isValid(newx,newy,n) && grid[newx][newy]==1){
                            int newNode = (newx)*n + newy;
                            ds.unionS(node,newNode);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int> se;
                    for(int ind=0;ind<4;ind++){
                        int newx = i + dx[ind];
                        int newy = j + dy[ind];
                        if(isValid(newx,newy,n) && grid[newx][newy]==1){
                            se.insert(ds.upar(newx*n+newy));
                        }
                    }
                    int temp = 1;
                    for(auto i:se){
                        temp+=ds.size[i];
                    }
                    ans = max(ans,temp);
                }
            }
        } 
        for(int i=0;i<n*n;i++){
            ans = max(ans,ds.size[ds.upar(i)]);
        }
        return ans;
    }
};