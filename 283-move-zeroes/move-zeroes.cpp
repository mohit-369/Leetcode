class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int zi = -1;

        for(int i = 0; i < nums.size(); i++)
        {
            if(zi != -1 && zi < i && nums[i] != 0)
            {
                nums[zi] = nums[i];

                nums[i] = 0;

                zi++;
            }

            if(zi == -1 && nums[i] == 0)
            {
                zi = i;
            }
        }
        

        return ;
    }
};