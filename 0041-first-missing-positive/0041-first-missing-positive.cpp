class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0) nums[i]=0;
        }

        int n=nums.size();



        for(auto it:nums)
        {
            int idx=abs(it);

            if(idx!=0 && idx<=n)
            {
                if(nums[idx-1]==0)
                {
                    nums[idx-1]=-(n+1);
                }

                else if(nums[idx-1]>0)
                {
                    nums[idx-1]=-nums[idx-1];
                }
            }
        }

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0) return i+1; 
        }

        return nums.size()+1;
        
    }
};