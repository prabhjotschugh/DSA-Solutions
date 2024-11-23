class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size(), cols = box[0].size();
        vector<vector<char>> result(cols, vector<char>(rows, '.')); 
        
        for (int i = 0; i < rows; i++) {
            int emptyPosition = cols - 1; 
            for (int j = cols - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    result[j][rows - i - 1] = '*';
                    emptyPosition = j - 1;
                } else if (box[i][j] == '#') {
                    result[emptyPosition][rows - i - 1] = '#';
                    emptyPosition--;
                }
            }
        }
        
        return result;
    }
};