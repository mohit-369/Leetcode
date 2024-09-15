class Solution {
int solve(int preIndex, int index, vector<int> &nums,vector<vector<int>> &dp)
{
    if(index < 0) return 0;

    if(dp[index][preIndex] != -1) return dp[index][preIndex];

    int nottake = solve(preIndex,index-1,nums,dp);

    int take = 0;

    if(preIndex == nums.size() || nums[index] < nums[preIndex])
    {
        take = 1 + solve(index,index-1,nums,dp);
    }

    return dp[index][preIndex] = max(take,nottake);
}
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));

        return solve(nums.size(),nums.size() - 1,nums,dp);
        
    }
};