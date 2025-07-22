class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        set<int> st;

        int head = 0;

        int tail = 0;

        int ans = 0;

        int sum = 0;

        while(head < nums.size())
        {
            if(st.find(nums[head]) == st.end())
            {
                sum += nums[head];

                ans = max(ans,sum);

                st.insert(nums[head]);

                head++;
            }

            else
            {
                while(tail <= head && st.find(nums[head]) != st.end())
                {
                    sum -= nums[tail];
                    st.erase(nums[tail]);
                    tail++;
                }

                
            }
        }

        return ans;
        
    }
};