class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {

        int ans = 0;

        unordered_map<int,int> mpp;

        for(auto &it:arr)
        {
            int ele = it - difference;

            if(mpp.find(ele) != mpp.end())
            {
                mpp[it] = 1 + mpp[ele];
            }

            else
            {
                mpp[it] = 1;
            }

            ans = max(ans, mpp[it]);
        }

        return ans;
        
    }
};