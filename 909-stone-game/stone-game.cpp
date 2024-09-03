class Solution {
int solve(int s, int e, int turn, vector<int> &piles,vector<vector<vector<int>>> &dp)
{
    if(s>e)
    {
        return 0;
    }

    if(dp[s][e][turn]!=-1) return dp[s][e][turn];

    if(turn)
    {
        int a = piles[s]+solve(s+1,e,0,piles,dp);

        int b = piles[e]+solve(s,e-1,0,piles,dp);

        return dp[s][e][turn]=max(a,b);

    }

    else
    {
        int a = solve(s+1,e,1,piles,dp)-piles[s];

        int b = solve(s,e-1,1,piles,dp) - piles[e];

        return dp[s][e][turn]=min(a,b);
    }
}
public:
    bool stoneGame(vector<int>& piles) {

        vector<vector<vector<int>>> dp(piles.size(),vector<vector<int>>(piles.size(),vector<int>(2,-1)));

        return solve(0,piles.size()-1,1,piles,dp)>0?1:0;

        
        
    }
};