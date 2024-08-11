class Solution {
public:
    void dfs(int i, int j,vector<vector<int>>& grid, vector<vector<bool>> &vis){
        if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || grid[i][j] == 0 || vis[i][j] == true) return;
        vis[i][j] = true;
        dfs(i+1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j-1,grid,vis);    
    }

    int count_islands(vector<vector<int>>& grid){
      vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(),false));
        int cnt =0 ;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        if(count_islands(grid) == 0 || count_islands(grid)> 1) return 0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0;j<grid[i].size(); j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    int cnt = count_islands(grid);
                    if(cnt > 1 || cnt == 0) return 1;
                    else grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};