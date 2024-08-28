class Solution {
int solve(int index,int buy,vector<int> &prices,vector<vector<int>> &dp)
{
    if(index >= prices.size()) return 0;

    if(dp[index][buy]!=-1) return dp[index][buy];

    if(buy)
    {
        int buyKaro = -prices[index]+solve(index+1,0,prices,dp);

        int skipKaro = 0+solve(index+1,buy,prices,dp);

        return dp[index][buy] = max(buyKaro,skipKaro);
    }

    else
    {
        int sellKaro = prices[index]+solve(index+2,1,prices,dp);

        int skipKaro = 0+solve(index+1,buy,prices,dp);

        return dp[index][buy] = max(sellKaro,skipKaro);
    }
}
public:
    int maxProfit(vector<int>& prices) {

        vector<vector<int>> dp(prices.size()+2,vector<int>(2,0));


        for(int index = prices.size()-1; index >= 0; index--)
        {
            for(int buy = 0; buy<=1; buy++)
            {
                if(buy)
                {
                    int buyKaro = -prices[index] + dp[index+1][0];

                    int skipKaro = 0 + dp[index+1][buy];

                    dp[index][buy]=max(buyKaro,skipKaro);
                }

                else
                {
                    int sellKaro = prices[index] + dp[index+2][1];

                    int skipKaro = dp[index+1][buy];

                    dp[index][buy]=max(sellKaro,skipKaro);
                }
            }
        }



        return dp[0][1];
        
    }
};