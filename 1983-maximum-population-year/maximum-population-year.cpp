class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        int temp = -1;

        int year = -1;

        map<int,int> mpp;

        for(auto &it:logs)
        {
            mpp[it[0]]+=1;

            mpp[it[1]]-=1;
        }

        int total = 0;

        for(auto &it:mpp)
        {
            total += it.second;

            if(total > temp)
            {
                temp = total;

                year = it.first;
            }
        }

        return year;
        
    }
};