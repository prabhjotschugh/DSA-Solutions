class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        int vp = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {}
                else read(i, j, grid, m, n, ans, vp);
            }
        }
        return ans;
    }
private:
    void read(int i, int j, vector<vector<int>>& grid, int& m, int& n, int& ans, int& vp) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return;
        else {
            int f = grid[i][j];
            vp += f;
            grid[i][j] = 0;
            ans = max(vp, ans);
            read(i + 1, j, grid, m, n, ans, vp);
            read(i - 1, j, grid, m, n, ans, vp);
            read(i, j + 1, grid, m, n, ans, vp);
            read(i, j - 1, grid, m, n, ans, vp);
            vp -= f;
            grid[i][j] = f;
        }
    }
};
