class Solution {
int solve(vector<int> &nums,int index,vector<int> &dp)
{
    if(index<0) return 0;

    if(dp[index]!=-1) return dp[index];

    int take = nums[index] + solve(nums,index-2,dp);

    int notake = solve(nums,index-1,dp);

    return dp[index]=max(take,notake);
}
public:
    int rob(vector<int>& nums) {

        vector<int> dp(nums.size(),-1);

        return solve(nums,nums.size()-1,dp);
        
    }
};