class Solution {
int solve(int index,vector<int> &prices,int sell,vector<vector<int>> &dp)
{

    if(index==0 && sell)
    {
        return INT_MIN;

    }

    if(index==0 && !sell)
    {
        return prices[index];
    }

    if(dp[index][sell]!=-1) return dp[index][sell];



    int notsale = solve(index-1,prices,sell,dp);

    int sale=INT_MIN;

    if(sell)
    {
        sale = prices[index]-solve(index-1,prices,0,dp);

        return dp[index][sell]= max(notsale,sale);
    }

    return dp[index][sell]=min(prices[index],notsale);
}
public:
    int maxProfit(vector<int>& prices) {

        int mi = prices[0];

        int res = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            res = max(res,prices[i] - mi);

            mi = min(mi,prices[i]);
        }

        return res;
        
    }
};