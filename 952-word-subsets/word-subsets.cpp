class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {


        vector<int> mpp(26,0);

        vector<string> ans;

        for(auto &it:words2)
        {
            vector<int> temp(26,0);

            for(int i = 0; i < it.size(); i++)
            {
                temp[it[i] - 'a']++;
            }

            for(int i = 0; i < 26; i++)
            {
                mpp[i] = max(mpp[i],temp[i]);
            }
        }

        for(auto &it:words1)
        {
            vector<int> temp(26,0);

            for(int i = 0; i < it.size(); i++)
            {
                temp[it[i] - 'a']++;
            }

            int flag = 1;

            for(int i = 0; i < 26; i++)
            {
                if(mpp[i] > temp[i])
                {
                    flag = 0;
                    break;
                }
            }

            if(flag) ans.push_back(it);
        }

        return ans;


        
        
    }
};