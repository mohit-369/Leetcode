class Solution {
public:
    bool canPalace(int row, int col, int ele, vector<vector<char>>& board)
    {
        char ch = ele + '0';

        for(int i = 0; i < 9; i++)
        {
            if(board[row][i] == ch) return false;
        }

        for(int i = 0; i < 9; i++)
        {
            if(board[i][col] == ch) return false;
        }

        int startRow = row - row % 3;
        int startCol = col - col % 3;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[startRow + i][startCol + j] == ch) return false;
            }
        }

        return true;
    }
    bool  solve(int row, int col, vector<vector<char>>& board)
    {
        if(col == 9)
        {
            col = 0;
            row = row + 1;
        }

        if(row == 9) return true;

        if(board[row][col] != '.')
        {
            return solve(row,col+1,board);
        }

        for(int i = 1; i <= 9; i++)
        {
            if(canPalace(row,col,i,board))
            {
                board[row][col] = '0' + i;
                if(solve(row,col+1,board)) return true;
                board[row][col] = '.';
            }
        }

        return false;

        
    }
    void solveSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    solve(i,j,board);
                    return;
                }
            }
        }

        return ;
        
    }
};