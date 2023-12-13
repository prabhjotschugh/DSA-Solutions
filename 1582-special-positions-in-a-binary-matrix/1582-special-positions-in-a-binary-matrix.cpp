class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> countRow(m, 0), countCol(n, 0);
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 1) {
                    countRow[r]++, countCol[c]++;
                }
            }
        }

        int result = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if ((mat[r][c] == 1) && (countRow[r] == 1) && (countCol[c] == 1)) result++;
            }
        }
        return result;
    }
};