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

        // vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));

        vector<int> curr(2,0);

        vector<int> next = curr;

        // return solve(0,prices,1,fee,dp);


        for(int index = prices.size()-1; index >= 0; index--)
        {
            for(int buy = 0; buy <=1; buy++)
            {
                if(buy)
                {
                    int buyKaro = -prices[index] + next[0];

                    int skipKaro = next[1];

                    curr[buy] = max(buyKaro,skipKaro);
                }

                else
                {
                    int sellKaro = prices[index] + next[1]-fee;

                    int skipKaro = next[0];

                    curr[buy] = max(sellKaro,skipKaro);
                }
            }

            next = curr;
        }



        return curr[1];


        
    }
};