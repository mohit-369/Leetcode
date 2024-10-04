class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {


        int ans = 0;

        sort(nums.begin(),nums.end());

        int start = 0;

        int end = nums.size() -1;

        while(start < end)
        {
            if(nums[start] + nums[end] == k)
            {
                ans++;
                start++;
                end--;
            }

            else if(nums[start] + nums[end] < k)
            {
                start++;
            }

            else
            {
                end--;
            }
        }

        return ans;
        
    }
};