class Solution {
int solve(int index, vector<int> &prices, int buy, int fee,vector<vector<int>> &dp)
{
    if(index==prices.size()) return 0;

    if(dp[index][buy]!=-1) return dp[index][buy];


    if(buy)
    {
        int buyKaro = -prices[index]+solve(index+1,prices,0,fee,dp);

        int skipKaro = solve(index+1,prices,buy,fee,dp);

        return dp[index][buy] = max(buyKaro,skipKaro);
    }

    else
    {
        int sellKaro = prices[index]+solve(index+1,prices,1,fee,dp)-fee;

        int skipKaro = solve(index+1,prices,0,fee,dp);

        return dp[index][buy] = max(sellKaro,skipKaro);
    }
}
public:
    int maxProfit(vector<int>& prices, int fee) {

        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));

        return solve(0,prices,1,fee,dp);
        
    }
};