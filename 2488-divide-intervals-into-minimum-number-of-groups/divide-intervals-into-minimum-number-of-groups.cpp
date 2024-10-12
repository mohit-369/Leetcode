class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        int ans = 0;

        map<int,int> mpp;

        for(auto &it:intervals) 
        {
            mpp[it[0]] += 1;

            mpp[it[1] + 1] -= 1;
        }

        int temp = 0;

        for(auto &it:mpp)
        {
            temp += it.second;

            ans = max(ans,temp);
        }

        return  ans;




        
    }
};