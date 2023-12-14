class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<int> Row(n, 0), Col(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int&& x=grid[i][j]==1;
                Row[i]+=x;
                Col[j]+=x;
            }
        }

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                grid[i][j]=2*(Row[i]+Col[j])-(n+m);
            }
        return grid;
    }
};