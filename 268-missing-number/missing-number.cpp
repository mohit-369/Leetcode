class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int ans = 0;

        for(auto &it:nums)
        {
            ans^=it;
        }

        for(int i = 0; i <= nums.size(); i++)
        {
            ans^=i;
        }

        return ans;
        
    }
};