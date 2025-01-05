class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        map<int,int> mpp;

        for(auto &it:shifts)
        {
            int x = it[0];
            int y = it[1];
            int z = it[2];
            if(z == 0)
            {
                mpp[x] -= 1;
                mpp[y + 1] += 1;
            }
            else
            { 
                mpp[x] += 1;
                mpp[y + 1] -= 1; 
            }
        }
        

        int shift = 0;

        string ans;

        for(int i = 0; i < s.size(); i++)
        {
            if(mpp.find(i) != mpp.end()) shift += mpp[i];

            int x = (s[i] - 'a' + shift) % 26;

            x = (x + 26) % 26;

            char ch = x + 'a';

            ans.push_back(ch);
        }

        return ans;
    }
};