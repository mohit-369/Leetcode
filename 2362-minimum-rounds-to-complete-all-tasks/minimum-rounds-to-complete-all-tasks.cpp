class Solution {
int solve(int ele,vector<int> &dp)
{
    if(ele == 0) return 0;

    if(ele == 2) return 1;

    if(ele < 2) return INT_MAX;

    if(dp[ele] != -1) return dp[ele];

    int case1 = solve(ele - 2,dp);

    int case2 = solve(ele - 3,dp);

    if(case1 != INT_MAX)
    {
        case1++;
    }

    if(case2 != INT_MAX)
    {
        case2++;
    }

    return dp[ele] = min(case1,case2);
}
public:
    int minimumRounds(vector<int>& tasks) {

        map<int,int> mpp;

        for(auto &ele:tasks) mpp[ele]++;

        int ans = 0;

        for(auto &it:mpp)
        {
            vector<int> dp(it.second + 1,-1);
            if(it.second == 1) return -1;

            ans += solve(it.second,dp);
        }

        return ans;
        
    }
};