class Solution {
int solve(int startRow, int startCol, int rowNo, int colNo, int  move,vector<vector<vector<int>>> &dp,int mod)
{
    if(startRow<0 || startCol<0 || startRow>=rowNo || startCol>=colNo) return 1;

    if(move==0) return 0;

    if(dp[startRow][startCol][move]!=-1) return dp[startRow][startCol][move];

    int ans = 0;

    ans=(ans%mod+solve(startRow-1,startCol,rowNo,colNo,move-1,dp,mod)%mod)%mod;

    ans=(ans%mod+solve(startRow+1,startCol,rowNo,colNo,move-1,dp,mod)%mod)%mod;

    ans=(ans%mod+solve(startRow,startCol-1,rowNo,colNo,move-1,dp,mod)%mod)%mod;

    ans=(ans%mod+solve(startRow,startCol+1,rowNo,colNo,move-1,dp,mod)%mod)%mod;

    return dp[startRow][startCol][move] = ans%mod;
}
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {


        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));

        int mod = 1e9+7;

        return solve(startRow,startColumn,m,n,maxMove,dp,mod);
        
    }
};