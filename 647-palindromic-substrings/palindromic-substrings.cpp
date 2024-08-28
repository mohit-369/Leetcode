class Solution {
int solve(int start, int end, string &s,vector<vector<int>> &dp)
{
    if(start>end) return 1;

    if(dp[start][end]!=-1) return dp[start][end];

    if(s[start] != s[end]) return 0;

    return dp[start][end]=solve(start+1,end-1,s,dp);
}
public:
    int countSubstrings(string s) {


        int ans = 0;

        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));

        for(int start = 0; start < s.size(); start++)
        {
            for(int end = start; end < s.size(); end++)
            {
                if(solve(start,end,s,dp)) ans++;
            }
        }

        return ans;
        
    }


};