class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        map<int,int> mpp;

        for(auto &it:trips)
        {
            mpp[it[1]] += it[0];

            mpp[it[2]] -= it[0];
        }

        int count = 0;

        for(auto &it:mpp)
        {
            count += it.second;

            if(count > capacity) return 0;
        }

        return 1;
        
    }
};