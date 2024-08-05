class Solution {
int solve(vector<int> &coins,int amount,int index,vector<vector<int>> &dp)
{
    if(amount==0) return 0;

    if(amount !=0 && index<0 ) return INT_MAX;

    if(dp[index][amount]!=-1) return dp[index][amount];

    int notTake=solve(coins,amount,index-1,dp);

    int take=INT_MAX;

    if(coins[index]<=amount)
    {
        int callAgain =solve(coins,amount-coins[index],index,dp);

        if(callAgain!=INT_MAX)
        {
            callAgain+=1;

            take=min(take,callAgain);
        }
    }

    return dp[index][amount] = min(take,notTake);


}
public:
    int coinChange(vector<int>& coins, int amount) {

        sort(coins.begin(),coins.end());

        int coins_number=coins.size();



        vector<vector<int>> dp(coins_number,vector<int>(amount+1,-1));

        int ans=solve(coins,amount,coins.size()-1,dp);

       


        if(ans==INT_MAX) return -1;

        return ans;
        
    }
};