class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int ans=0;

        if(k==0 or k==1) return 0;

        int product=1;

        while(j<nums.size())
        {
            product*=nums[j];
            while(product>=k)
            {
                product=product/nums[i];
                i++;
            }

            ans+=j-i+1;

            j++;
        }

        return ans;
    }
};