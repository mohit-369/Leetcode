class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        long long int ans=0;

        int i=0,j=0;

        int ma=*max_element(nums.begin(),nums.end());

        int count=0;

        int n=nums.size();

        while(j<n)
        {
            if(nums[j]==ma) count++;

            while(count>=k)
            {
                if(nums[i]==ma) count--;

                i++;
            }

            ans+=i;

            j++;
        }

        return ans;
        
    }
};