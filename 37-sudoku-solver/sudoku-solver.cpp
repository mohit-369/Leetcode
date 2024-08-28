class Solution {
bool isValid(int row,int col,char ch,vector<vector<char>> &temp)
{
    for(int i = 0; i < 9; i++)
    {
        if(temp[row][i]==ch) return 0;

        if(temp[i][col]==ch) return 0;
    }

    // checking in square;

    int rowStart = (row/3)*3;

    int colStart = (col/3)*3;

    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            if(temp[rowStart+row][colStart+col]==ch) return 0;
        }
    }

    return 1;

}
void solve(int row, int col, vector<vector<char>> &board,vector<vector<char>> &temp)
{
    if(row == board.size())
    {
        board = temp;

        return;
    }

    if(temp[row][col] == '.')
    {
        for(char ch = '1'; ch <= '9'; ch++)
        {
            if(isValid(row,col,ch,temp))
            {
                temp[row][col]=ch;
                
                if(col==8)
                {
                    solve(row+1,0,board,temp);
                }

                else
                {
                    solve(row,col+1,board,temp);
                }

                temp[row][col]='.';
            }
        }
    }

    else
    {
        if(col==8)
        {
        solve(row+1,0,board,temp);
        }

        else
        {
        solve(row,col+1,board,temp);
        }

    }

    return;
}
public:
    void solveSudoku(vector<vector<char>>& board) {

        int row = 0;

        int col = 0;

        vector<vector<char>> temp = board;

        solve(row, col, board,temp);

        return;
        
    }
};