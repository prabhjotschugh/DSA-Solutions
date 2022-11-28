class Solution {
public:
    int counter=0;
    
    int totalNQueens(int n) {
        placeNQueens(n);
        return counter;
    }
    int board[11][11];

    bool isPossible(int n, int row, int col)
    {
        for (int i = row - 1; i >= 0; i--)
            if (board[i][col] == 1)
                return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1)
                return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 1)
                return false;
        return true;
    }

    void nQueenHelper(int n, int row)
    {
        if (row == n)
        {
            counter++;
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (isPossible(n, row, j))
                {
                    board[row][j] = 1;
                    nQueenHelper(n, row + 1);
                    board[row][j] = 0;
                }
            }
        }
    }

    void placeNQueens(int n)
    {
        memset(board, 0, 11 * 11 * sizeof(int));
        nQueenHelper(n, 0);
    }
};