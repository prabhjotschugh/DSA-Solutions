class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bitset<200> col0=0, row0=0;
        const int n=matrix.size(), m=matrix[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                if (matrix[i][j]==0){
                    row0[i]=1;
                    col0[j]=1;
                }
            }
        for(int i=0; i<n; i++){
            if (row0[i])
                fill(matrix[i].begin(), matrix[i].end(), 0);
        }
        for(int j=0; j<m; j++){
            if (!col0[j]) continue;
            for(int i=0; i<n; i++)
                matrix[i][j]=0;
        }
    }
};