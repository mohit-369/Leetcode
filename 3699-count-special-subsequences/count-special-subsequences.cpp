class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {

        long long ans = 0;

        unordered_map<double,vector<int>> mpp;

        for(int p = 0; p < nums.size(); p++)
        {
            for(int q = p + 2; q < nums.size() - 4; q++)
            {
                mpp[1.0 * nums[p] / nums[q]].push_back(q);
            }
        }

        for(auto &it:mpp) sort(it.second.begin(),it.second.end());

        for(int r = 4; r < nums.size(); r++)
        {
            for(int s = r + 2; s < nums.size(); s++)
            {
                long long int cnt = upper_bound(mpp[1.0*nums[s]/nums[r]].begin(),mpp[1.0*nums[s]/nums[r]].end(),r-2) - mpp[1.0*nums[s]/nums[r]].begin();
                ans += cnt;
            }
        }

        return ans;


        
    }
};