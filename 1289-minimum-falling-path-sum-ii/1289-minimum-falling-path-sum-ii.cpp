class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 1; i < n; i++) {
            int min1 = INT_MAX, min2 = INT_MAX, idx1 = -1;
            for (int j = 0; j < n; j++) {
                if (grid[i - 1][j] < min1) {
                    min2 = min1;
                    min1 = grid[i - 1][j];
                    idx1 = j;
                } else if (grid[i - 1][j] < min2 && idx1 != j) {
                    min2 = grid[i - 1][j];
                }
            }
            for (int j = 0; j < n; j++) {
                grid[i][j] += (j == idx1 ? min2 : min1);
            }
        }
        return *min_element(grid[n - 1].begin(), grid[n - 1].end());
    }
};