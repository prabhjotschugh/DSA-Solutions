class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j!=0) grid[i][j]+=grid[i][j-1];
                if(j==0 and i!=0) grid[i][j]+=grid[i-1][j];
                if(i!=0 and j!=0) grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[n-1][m-1];
    }
};