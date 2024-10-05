class Solution {
public:
    int minAddToMakeValid(string s) {

        int cnt = 0;

        int ans = 0;

        for(auto &it:s)
        {
            if(cnt == 0 && it == ')') ans++;

            else if(it == '(') cnt++;

            else if( cnt > 0 && it == ')') cnt--;


        }

        return ans + cnt;
        
    }
};