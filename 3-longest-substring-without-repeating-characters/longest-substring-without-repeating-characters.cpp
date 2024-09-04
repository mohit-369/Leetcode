class Solution {
public:
    int lengthOfLongestSubstring(string s) {


        int ans = 0;

        int start = 0;

        int end = 0;

        vector<int> mp(256,0);

        while(end<s.size())
        {
            mp[s[end]]++;

            while(mp[s[end]]>1)
            {
                mp[s[start]]--;

                start++;
            }

            ans = max(ans,end-start+1);

            end++;
        }

        return ans;
        
    }
};