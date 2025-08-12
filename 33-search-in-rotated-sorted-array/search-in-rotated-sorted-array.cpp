class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0;

        int high = nums.size() - 1;

        while(high - low > 1)
        {
            int mid = (high - low)/2 + low;

            if(nums[mid] == target) return mid;

            else if(nums[low] <= nums[mid])
            {
                if(nums[low] <= target && target < nums[mid])
                {
                    high = mid;
                }

                else 
                {
                    low = mid;
                }
            }

            else
            {
                if(nums[mid] < target && target <= nums[high])
                {
                    low = mid;
                }

                else
                {
                    high = mid;
                }
            }
        }

        if(nums[low] == target) return low;

        if(nums[high] == target) return high;

        return -1;
    }
};