class Solution {
bool solve(int idx, int count,string &s,vector<vector<int>> &dp)
{

    if(idx == s.size())
    {
        return count == 0;
    }

    if(dp[idx][count] != -1) return dp[idx][count];


    if(s[idx] == '(')
    {
        return dp[idx][count] = solve(idx+1,count + 1,s,dp);
    }

    else if(s[idx] == ')')
    {
        if(count)
        {
           return dp[idx][count] = solve(idx+1,count - 1,s,dp);
        }

        return 0;
    }

    int a = solve(idx + 1, count, s,dp);

    int b = solve(idx + 1, count + 1, s,dp);

    int c = 0;

    if(count)
    {
        c = solve(idx +1, count - 1, s,dp);
    }

    return dp[idx][count] = a || b || c;


}
public:
    bool checkValidString(string s) {

        vector<vector<int>> dp(s.size() + 1,vector<int> (s.size(),-1));

        return solve(0,0,s,dp);
        
    }
};