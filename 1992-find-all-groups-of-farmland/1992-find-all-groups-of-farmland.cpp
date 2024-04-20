class Solution {
public:
        void dfs(vector<vector<int>>& land, vector<vector<bool>>& vis, int r, int c, vector<int>& temp) {
        int row = land.size();
        int col = land[0].size();
        vis[r][c] = true; 
        if (c == col - 1 && r == row - 1) {
            temp.push_back(r);
            temp.push_back(c);
        }
        else if (r + 1 <= row - 1 && c + 1 <= col - 1 && land[r + 1][c] == 0 && land[r][c + 1] == 0) {
            temp.push_back(r);
            temp.push_back(c);
        }
        else if (c == col - 1 && land[r + 1][c] == 0) {
            temp.push_back(r);
            temp.push_back(c);
        }
        else if (r == row - 1 && land[r][c + 1] == 0) {
            temp.push_back(r);
            temp.push_back(c);
        }
        int dp1[4] = {0, 0, -1, 1};
        int dp2[4] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int currRow = dp1[i] + r;
            int currCol = dp2[i] + c;
            if (currRow >= 0 && currCol >= 0 && currCol < col && currRow < row && land[currRow][currCol] == 1 && !vis[currRow][currCol])
                dfs(land, vis, currRow, currCol, temp);
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = land.size();
        int col = land[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                vector<int> temp;
                if (!vis[i][j] && land[i][j] == 1) {
                    temp.push_back(i);
                    temp.push_back(j);
                    dfs(land, vis, i, j, temp); 
                    ans.push_back(temp); 
                }
            }
        }
        return ans;
    }
};