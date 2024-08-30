class Solution {
int solve(int index,vector<int> &nums, int target, unordered_map<int,int> &mpp)
{
    if(target == 0) return 1;

    if(target && index<0) return 0;

    if(target < 0) return 0;

    if(mpp.find(target)!=mpp.end()) return mpp[target];

    int res = 0;

    for(int i = nums.size()-1; i >= 0; i--)
    {
        // int nottake = solve(i-1,nums,target);

        int take = solve(i,nums,target-nums[i],mpp);

        res+=take;
    }

    return mpp[target]=res;
}
public:
    int combinationSum4(vector<int>& nums, int target) {

        unordered_map<int,int> mpp;


        return solve(nums.size()-1,nums,target,mpp);
        
    }
};