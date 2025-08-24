class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int tail = 0;
        int head = 0;
        int cnt = 0;
        int ans = 0;


        while(head < nums.size())
        {
            if(nums[head] == 0) cnt++;

            while(cnt > 1 && tail <= head)
            {
                if(nums[tail] == 0)
                {
                    cnt--;
                }
                tail++;
            }

            ans = max(ans,head - tail + 1 - cnt);
            head++;


        }    

        return ans == nums.size() ? ans - 1 : ans;  
    }
};