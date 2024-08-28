class Solution {
int solve(int index,int buy,vector<int> &prices,vector<vector<int>> &dp)
{

    if(index == prices.size()) return 0;

    if(dp[index][buy]!=-1) return dp[index][buy];
    
    if(buy)
    {
        int buyKaro = -prices[index]+solve(index+1,0,prices,dp);

        int skipKaro = solve(index+1,buy,prices,dp);

        return dp[index][buy] = max(buyKaro,skipKaro);
    }

    else
    {
        int sellKaro = prices[index]+solve(index+1,1,prices,dp);

        int skipKaro = solve(index+1,buy,prices,dp);

        return dp[index][buy] = max(sellKaro,skipKaro);
    }
}
public:
    int maxProfit(vector<int>& prices) {

        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));

        return solve(0,1,prices,dp);
    }
};