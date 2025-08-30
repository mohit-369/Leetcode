class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<int> row(9,0), col(9,0), square(9,0);

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '0' + 0;
                int mask = 1 << num;

                if(row[i] & (mask)) return false;
                row[i] |= mask;

                if(col[j] &(mask)) return false;
                col[j] |= mask;

                int boxindex = 3*(i / 3) + j / 3;

                if(square[boxindex] & mask) return false;
                square[boxindex] |= mask;
            }
        }

        return true;

    }
};