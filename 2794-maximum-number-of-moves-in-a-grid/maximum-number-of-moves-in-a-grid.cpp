class Solution {
int solve(int row, int col, int rows, int cols, vector<vector<int>>& grid,int dp[][1000])
{
    if(row >= rows || col >= cols) return 0;

    if(dp[row][col] != -1) return dp[row][col];

    int up = 0;

    int down = 0;

    int dig = 0;

    if(row - 1 >= 0 && col + 1 < cols && grid[row - 1][col + 1] >grid[row][col]) up = 1 + solve(row - 1, col + 1, rows, cols, grid, dp);
    if(col + 1 < cols && grid[row][col+1] > grid[row][col]) down = 1 + solve(row, col + 1, rows, cols, grid, dp);
    if(row + 1 < rows && col + 1 < cols && grid[row + 1][col + 1] > grid[row][col]) dig = 1 + solve(row+1,col+1,rows,cols,grid,dp);

    return dp[row][col] = max({up,down,dig});
}
public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int dp[rows][1000];
        int ans = 0;
        for(int row  = 0; row < rows; row++)
        {   memset(dp,-1,sizeof(dp));
            ans = max(ans, solve(row,0,rows,cols,grid,dp));
        }

        return ans;
        
    }
};