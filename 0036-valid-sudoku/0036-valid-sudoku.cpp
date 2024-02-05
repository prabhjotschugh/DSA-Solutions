class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10];
        int col[9][10];
        int block[9][10];

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.')
                    continue;
                int val = board[i][j] - '0';
                int blockNo = (i/3)*3 + (j/3);
                if(++row[i][val] > 1 || ++col[j][val] > 1 || ++block[blockNo][val] > 1) {
                    return false;
                }
            }
        }

        return true;
    }
};