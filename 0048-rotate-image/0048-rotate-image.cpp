class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int ro = matrix.size();
        for(int i = 0 ;i< matrix.size()/2;i++){
            for(int j = 0;j< matrix[i].size(); j++)
                swap(matrix[i][j],matrix[ro-i-1][j]);
        }
        for(int i = 0; i< ro; i++){
            cout<<i<<ro-i-1<<endl;
            for(int j = i+1;j<ro ; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};