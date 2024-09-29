class Solution {
public:
    int findMin(vector<int>& nums) {

        int s = 0;

        int e = nums.size() - 1;

        if(nums[0] <= nums[e]) return nums[0];

        while(e - s > 1)
        {
            int mid = (e-s)/2 + s;

            if(nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1])
            {
                return nums[mid];
            }

            else if(nums[mid] < nums[e] && nums[mid] > nums[s]) e = mid-1;

            else if(nums[mid] < nums[e] && nums[mid] < nums[s])
            {
                e = mid-1;
            }

            else
            {
                s = mid + 1;
            }
        }

        if(nums[s] < nums[e]) return nums[s];

        return nums[e];
        
    }
};