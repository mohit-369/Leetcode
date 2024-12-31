class Solution {
int findidx(int x, vector<int> &days)
{
    int idx = upper_bound(days.begin(),days.end(),x) - days.begin();

    // cout<<idx<<endl;

    return idx;
}
int solve(int idx, vector<int> &days, vector<int> &costs, vector<int> &dp)
{
    if(idx == days.size()) return 0;

    if(dp[idx] != -1) return dp[idx];

    int oneday = costs[0] + solve(idx + 1,days,costs,dp);

    int nextIdx = findidx(days[idx] + 6,days);

    int sevenday = costs[1] + ((nextIdx < days.size()) ? solve(nextIdx,days,costs,dp) : 0);

    nextIdx = findidx(days[idx] + 29, days);

    int thirday = costs[2] + ((nextIdx < days.size()) ? solve(nextIdx,days,costs,dp) : 0);

    return dp[idx] = min({oneday,sevenday,thirday});
}
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        vector<int> dp(366,-1);

        return solve(0,days,costs,dp);

        // cout<<findidx(days[0],days)<<" "<<findidx(days[0] + 6,days)<<" "<<findidx(days[0] + 30,days)<<endl;

        return 0;

        
    }
};