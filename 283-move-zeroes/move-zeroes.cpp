class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int curr = 0;

        int pos = 0;

        while(curr < nums.size())
        {
            if(nums[curr] != 0)
            {
                swap(nums[curr],nums[pos]);

                pos++;
            }

            curr++;
        }

        return ;
        
    }
};