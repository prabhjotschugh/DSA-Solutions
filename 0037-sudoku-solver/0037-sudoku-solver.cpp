class Solution {
public:
    bool isSafe(int curr_row, int curr_col, vector<vector<char>>& board, char value){
        int n = board.size();
        for(int col=0; col<n; col++){
            if(board[curr_row][col] == value){
                return false;
            }
        }
        for(int row=0; row<n; row++){
            if(board[row][curr_col] == value){
                return false;
            }
        }
        for(int i=0; i<9; i++){
            if(board[3*(curr_row/3)+(i/3)][3*(curr_col/3)+(i%3)] == value){
                return false;
            }
        }
        return true;
    }


    bool solve(vector<vector<char>>& board){
        int n = board.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                //check for empty cell
                if(board[i][j] == '.'){
                    for(char value = '1'; value<='9'; value++){
                        if(isSafe(i, j, board, value)){
                            board[i][j] = value;
                            bool nextSolution = solve(board);
                            if(nextSolution == true){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};