class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        unordered_map<int,int> mpp;

        int ans=INT_MIN;

        int i=0,j=0;

        int n=nums.size();

        while(j<n)
        {
            mpp[nums[j]]++;

            while(mpp[nums[j]]>k)
            {
                mpp[nums[i]]--;

                i++;
            }

            ans=max(ans,j-i+1);

            j++;

        }

        return ans;


        
    }
};