class Solution {
int solve(vector<vector<int>> &grid,int row, int col,vector<vector<int>> &dp)
{
    if(row<0 || col<0) return INT_MAX;

    if(dp[row][col]!=-1) return dp[row][col];

    int ans=min(solve(grid,row-1,col,dp),solve(grid,row,col-1,dp));

    if(ans!=INT_MAX)
    {
        return dp[row][col]=grid[row][col]+ans;
    }

    return dp[row][col]=grid[row][col];


}
public:
    int minPathSum(vector<vector<int>>& grid) {

        int noOfRow = grid.size();

        int noOfCol = grid[0].size();

        vector<vector<int>> dp(noOfRow,vector<int> (noOfCol,-1));


        return solve(grid,noOfRow-1,noOfCol-1,dp);
        
    }
};