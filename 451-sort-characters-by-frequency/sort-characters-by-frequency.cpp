class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> mpp;

        for(auto &ele:s)
        {
            mpp[ele]++;
        }

        auto cmp = [&](char a,char b)
        {
            if(mpp[a] == mpp[b])
            {
                return a < b;
            }
            return mpp[a] > mpp[b];
        };

        sort(s.begin(),s.end(),cmp);

        return s;
        
    }
};