class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int column = 0;
        int row = matrix.size()-1;
        
        while(row<=matrix.size() and column<matrix[0].size()){
            if(matrix[row][column] == target){
                return true;
            }
            else if(matrix[row][column]>target){
                row--;
            }
            else{
                column++;
            }
        }
        return false;
    }
};