class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int N = grid.size();
        int min_path_sum = INT_MAX;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for(int i = 0; i < N; i++)
            dp[0][i] = grid[0][i];
        
        for(int i = 1; i < N; i++) {
            min_path_sum = INT_MAX;
            for(int j = 0; j < N; j++) {
                int top_left = j >= 1 ? dp[i-1][j-1] : INT_MAX;
                int top = dp[i-1][j];
                int top_right = j < N-1 ? dp[i-1][j+1] : INT_MAX;
                
                dp[i][j] = min({top_left, top, top_right}) + grid[i][j];
            }
        }
        return *min_element(dp[N-1].begin(), dp[N-1].end());
    }
};