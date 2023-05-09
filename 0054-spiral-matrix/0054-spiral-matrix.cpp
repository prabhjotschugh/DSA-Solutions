class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> list;
        int rowTop = 0;
        int rowBottom = matrix.size() - 1;
        int columnLeft = 0;
        int columnRight = matrix[0].size() - 1;

        int direction = 0; 

        while (rowTop <= rowBottom && columnLeft <= columnRight) {
            if (direction == 0) {
                for (int i = columnLeft; i <= columnRight; i++) {
                    list.push_back(matrix[rowTop][i]);
                }
                rowTop++;
                direction = (direction + 1) % 4;
            } else if (direction == 1) {
                for (int i = rowTop; i <= rowBottom; i++) {
                    list.push_back(matrix[i][columnRight]);
                }
                columnRight--;
                direction = (direction + 1) % 4;
            } else if (direction == 2) {
                for (int i = columnRight; i >= columnLeft; i--) {
                    list.push_back(matrix[rowBottom][i]);
                }
                rowBottom--;
                direction = (direction + 1) % 4;
            } else {
                for (int i = rowBottom; i >= rowTop; i--) {
                    list.push_back(matrix[i][columnLeft]);
                }
                columnLeft++;
                direction = (direction + 1) % 4;
            }
        }
        return list;
    }
};