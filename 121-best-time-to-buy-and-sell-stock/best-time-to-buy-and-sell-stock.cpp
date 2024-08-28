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

        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));

        int ans = solve(prices.size()-1,prices,1,dp);

        return ans<0?0:ans;
        
    }
};