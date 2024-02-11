class Solution {
int dp[71][71][71];
    int rows, cols;
    int dfs(int r, int c1, int c2, vector<vector<int>>& grid){
        if(c1 < 0 || c2 < 0 || c1 >= cols || c2 >= cols || c1 == c2) return 0;
        if(r == rows-1){
            return  grid[r][c1] + grid[r][c2];
        }
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        int ans = 0;
        for(int i = -1;i <= 1;i++){
            for(int j = -1;j <= 1;j++){
                ans = max(ans, 
                grid[r][c1] + grid[r][c2] + dfs(r+1, c1+i, c2+j, grid));
            }
        }
        return dp[r][c1][c2] = ans;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, cols-1, grid);
    }
};