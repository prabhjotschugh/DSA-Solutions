class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int i, int j){
        if(i>=0 && j>=0 && obstacleGrid[i][j] == 1)   return 0;
        
        if(i==0 && j==0)    return 1;
        if(i<0 || j<0)      return 0;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        int upPaths = solve(obstacleGrid, dp, i-1, j);
        int leftPaths = solve(obstacleGrid, dp, i, j-1);
        
        return dp[i][j] = upPaths + leftPaths;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(obstacleGrid, dp, n-1, m-1);
    }
};