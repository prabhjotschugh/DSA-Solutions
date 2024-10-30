class Solution {
public:
    int dp[1001][1001];
    int solve(vector<vector<int>>& grid, int prevr, int c){
        int n = grid.size();
        int m = grid[0].size();
        if(c == m-1){
            return 0;
        }
        if(dp[prevr][c]!=-1) return dp[prevr][c];
        int maxi = 0;
        for(int i=-1; i<=1; i++){
            int r = prevr+i;
            if(r<n && r>=0 && c<m-1 && grid[r][c+1] > grid[prevr][c]){
                maxi = max(maxi, 1+solve(grid, r, c+1));
            }
        }
        return dp[prevr][c] = maxi;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int maxi=0;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<grid.size(); i++){
            maxi = max(maxi, solve(grid, i, 0));
        }
        return maxi;
    }
};