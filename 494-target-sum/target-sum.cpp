class Solution {
int solve(int index, vector<int> &nums, int target)
{
    if(index < 0)
    {
        return target == 0;
    }

    int plus = solve(index-1,nums,target+nums[index]);

    int minus = solve(index-1,nums,target-nums[index]);

    return plus+minus;
}
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        return solve(nums.size()-1,nums,target);
        
    }
};