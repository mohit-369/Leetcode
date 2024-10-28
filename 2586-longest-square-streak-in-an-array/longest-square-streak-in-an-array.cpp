class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        int ans = 1;

        sort(nums.begin(),nums.end());

        int size = nums.size();

        multiset<long long > mt(nums.begin(),nums.end());



        for(int i = 0; i < size; i++)
        {
            int temp = 0;

            long long ele = nums[i]*1ll;

            while(mt.find(ele) != mt.end())
            {
                temp++;
                mt.erase(mt.find(ele));
                ele = ele*ele;
            }

            ans = max(ans,temp);
        }

        return ans == 1 ? -1 : ans;
        
    }
};