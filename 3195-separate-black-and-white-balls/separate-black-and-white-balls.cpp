class Solution {
public:
    long long minimumSteps(string s) {

        long long int ans = 0;

        int curr = 0;

        int pos = 0;

        while( curr < s.size())
        {
            if(s[curr] == '0')
            {
                ans += (curr - pos)*1ll;

                pos++;
            }

            curr++;
        }

        return ans;
        
    }
};