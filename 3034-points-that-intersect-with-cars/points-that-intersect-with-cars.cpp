class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {

        map<int,int> mpp;

        for(auto &it:nums)
        {
            mpp[it[0]] += 1;

            mpp[it[1]] += -1;
        }

        int start = -1;

        int ans = 0;

        int total = 0;

        for(auto &it:mpp)
        {

            total += it.second;

            if(total == 0 && start == -1)
            {
                ans += 1;
            }

            else if(start == -1)
            {
                start = it.first;
            }

            else if(total == 0 && start != -1)
            {
                ans += it.first - start + 1;

                start = -1;
            }

            
        }

        return ans;
        
    }
};