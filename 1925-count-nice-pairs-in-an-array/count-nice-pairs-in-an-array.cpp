class Solution {
int rev(int x)
{
    string a=to_string(x);

    reverse(a.begin(),a.end());

    return stoi(a);
}
public:
    int countNicePairs(vector<int>& nums) {

        unordered_map<int,int> mpp;

        int ans=0;

        int mod=1e9+7;

        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];

            int y=rev(nums[i]);

            ans=ans%mod+(mpp[x-y]++)%mod;
        }

        return ans%mod;
        
    }
};