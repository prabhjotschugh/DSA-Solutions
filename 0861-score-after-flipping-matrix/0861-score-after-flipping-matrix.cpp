class Solution {
public:
    void fliprow(vector<vector<int>>& grid, int m, int row){
        for(int i=0;i<m;i++)
            grid[row][i] ^= 1;
    }
    void flipcol(vector<vector<int>>& grid, int n, int col){
        for(int i=0;i<n;i++)
            grid[i][col] ^= 1;
    }

    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for(int i=0;i<n;i++)
            if(!grid[i][0]) fliprow(grid, m, i);

        for(int j=0;j<m;j++){
            int zero = 0;
            for(int i=0;i<n;i++)
                if(grid[i][j]==0) zero++;
            if(zero > (n-zero)) flipcol(grid, n, j);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            string binary;
            for(int j=0;j<m;j++)
                binary += to_string(grid[i][j]);
            ans += stoi(binary, NULL, 2);
        }
        return ans;
    }
};