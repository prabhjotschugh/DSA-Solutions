class Solution {
public:
    int findMax(vector<vector<int>>& grid,int i,int j){
        int maxi = INT_MIN;
        for(int x=i;x<i+3;x++){
            for(int y=j;y<j+3;y++){
                maxi = max(maxi,grid[x][y]);
            }
        }
        return maxi;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> v(n - 2, vector<int>(n - 2));
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<n-2;j++)
            {
                int max = findMax(grid,i,j);
                v[i][j] = max;
            }
        }
        return v;
    }
};