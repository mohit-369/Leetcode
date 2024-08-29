class Solution {
int solve(int i,int j,vector<vector<int>> &dp)
{
    if(i>=j) return 0;

    int res = INT_MAX;

    if(dp[i][j]!=-1) return dp[i][j];

    for(int num = i; num <=j; num++)
    {
        int temp = num;

        temp=temp+max(solve(i,num-1,dp),solve(num+1,j,dp));

        res = min(res,temp);
    }

    return dp[i][j]=res;
}
public:
    int getMoneyAmount(int n) {

       vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return solve(1,n,dp);
        
    }
};