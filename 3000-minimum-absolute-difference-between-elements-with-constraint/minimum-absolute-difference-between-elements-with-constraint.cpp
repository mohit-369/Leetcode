class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {

        set<int> mt;

        int ans = INT_MAX;

        for(int i = x; i < nums.size(); i++)
        {
            mt.insert(nums[i - x]);

            auto it = mt.upper_bound(nums[i]);

            if(it != mt.end()) ans = min(ans,abs(nums[i] - *it));

            if(it != mt.begin()) ans = min(ans, abs(nums[i] - *prev(it)));
        }

        return ans;
        
    }
};