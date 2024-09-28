class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ans = INT_MIN;

        int temp = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            temp = temp + nums[i];

            if(temp < 0)
            {
                temp = 0;
            }

            else
            {
                ans = max(ans,temp);
            }
        }

        return (ans != INT_MIN) ? ans :*max_element(nums.begin(),nums.end());
        
    }
};