class Solution {
int solve(vector<int> &nums,int k)
{
    int i=0,j=0;
    unordered_map<int,int> mpp;

    int n=nums.size();

    int res=0;

    while(j<n)
    {
        mpp[nums[j]]++;

        while(mpp.size()>k)
        {
            mpp[nums[i]]--;
            if(mpp[nums[i]]==0)
            {
                mpp.erase(nums[i]);
            }
            i++;
        }

        res+=j-i+1;

        j++;

    }

    return res;
}
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return solve(nums,k)-solve(nums,k-1);
        
    }
};