class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {

        vector<int> ans;

        unordered_map<long long,int> mpp;

        long long mod = 1011001110001111;

        long long bash = 31;





        for(auto &it:words)
        {
            string temp = it;

            long long hash = temp[0] - 'a' + 1;

            mpp[hash]++;

            long long pow = 31;

            for(int index = 1; index < temp.size(); index++)
            {
                hash = (hash + pow*(temp[index] - 'a' + 1)) % mod;

                mpp[hash]++;

                pow = (pow*bash) % mod;

               
            }


        }

         for(auto &it:words)
        {
            string temp = it;

            long long hash = temp[0] - 'a' + 1;

            int tans = mpp[hash];

            long long pow = 31;

            for(int index = 1; index < temp.size(); index++)
            {
                hash = (hash + pow*(temp[index] - 'a' + 1)) % mod;

                tans = (tans + mpp[hash]) % mod;

                pow = (pow*bash) % mod;

                
            }

            ans.push_back(tans);


        }

        return ans;
        
    }
};