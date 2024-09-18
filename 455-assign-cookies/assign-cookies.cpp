class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(),g.end());

        sort(s.begin(),s.end());

        int j = 0;

        int ans = 0;

        for(int i = 0; i < g.size();)
        {
            if(j < s.size() && g[i] <= s[j])
            {
                ans++;
                j++;
                i++;
            }

            else if( j == s.size()) break;

            else
            {
                j++;
            }

           
        }

        return ans;
        
    }
};