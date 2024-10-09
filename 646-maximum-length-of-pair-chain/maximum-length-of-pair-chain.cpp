class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        auto cmp = [&](vector<int> a,vector<int> b)
        {
            return a[1] < b[1];
        };

        sort(pairs.begin(),pairs.end(),cmp);

        int ans = -1;

        vector<int> pre = pairs[0];

        for(auto &it:pairs)
        {
            if(it[0] <= pre[1])
            {
                ans++;
            }

            else
            {
                pre = it;

            }
        }

        return pairs.size() - ans;



        
    }
};