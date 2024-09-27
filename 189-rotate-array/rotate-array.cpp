class Solution {
void rev(vector<int> &nums,int start, int end)
{
    while(start < end)
    {
        swap(nums[start++],nums[end--]);
    }

    return ;
}
public:
    void rotate(vector<int>& nums, int k) {

         k = k % nums.size();

        rev(nums,0,nums.size()-1);

        rev(nums,0,k-1);

        rev(nums,k,nums.size()-1);

        return ;
        
    }
};