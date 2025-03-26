class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int ele = (n*m)/2;
        int count = 0;
        for(int i=0;i<m*n;i++){
            if(abs(v[ele] - v[i]) % x) return -1;
            count += abs(v[ele] - v[i]) / x;
        }
        return count;
    }
};