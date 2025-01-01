class Solution {
public:
    int maxScore(string s) {

        int cnt0 = 0;

        int cnt1 = 0;

        for(auto &it:s)
        {
            if(it == '1') cnt1++;
        }

        int ans = 0;

        for(int i = 0; i < s.size() - 1; i++)
        {
            if(s[i] == '0') cnt0++;
            else cnt1--;
            ans = max(ans,cnt0 + cnt1);

            
        }

        return ans;


        
    }
};