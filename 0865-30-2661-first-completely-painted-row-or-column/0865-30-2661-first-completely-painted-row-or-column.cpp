class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int m=mat.size(), n=mat[0].size(), N=m*n;
        vector<int> idx(N+1);
        for(int i=0; i<N; i++)
            idx[arr[i]]=i;

        vector<int> to_i(N), to_j(N);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int pos=idx[mat[i][j]];
                to_i[pos]=i;
                to_j[pos]=j;
            }
        }
        vector<int> row(m), col(n);
        for(int i=0; i<N; i++){
            int pos=idx[arr[i]];
            if (++row[to_i[pos]]==n || ++col[to_j[pos]]==m) return i;
        }
        return -1;
    }
};