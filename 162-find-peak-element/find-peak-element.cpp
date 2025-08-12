class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while(high - low > 1)
        {
            int mid = (high - low) / 2+ low;

            if(nums[mid] > nums[mid-1])
            {
                low = mid;
            }

            else
            {
                high = mid;
            }
        }

        if(nums[low] < nums[high]) return high;
        return low;
        
    }
};