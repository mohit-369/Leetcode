class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i=-1;
        int j=0;

        if(nums.size()==1) return 1;

        while(j<nums.size()-1)
        {
            if(nums[j]!=nums[j+1])
            {
                i++;
                nums[i]=nums[j];
                j++;

            }

            else
            {
                
                while(j<nums.size()-1 && nums[j]==nums[j+1])
                {
                    j++;
                }
            }


        }

        if(nums[j]==nums[j-1])
        {
            i++;
            nums[i]=nums[j];
        }

        else
        {
            i++;
            nums[i]=nums[j];
        }

        return i+1;
        
    }
};