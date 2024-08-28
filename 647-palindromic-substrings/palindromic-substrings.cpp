class Solution {
int solve(int start, int end, string &s)
{
    if(start>end) return 1;

    if(s[start] != s[end]) return 0;

    return solve(start+1,end-1,s);
}
public:
    int countSubstrings(string s) {


        int ans = 0;

        for(int start = 0; start < s.size(); start++)
        {
            for(int end = start; end < s.size(); end++)
            {
                if(solve(start,end,s)) ans++;
            }
        }

        return ans;
        
    }


};