class Solution {
int solve(string s, int index,unordered_set<string> &st,unordered_map<int,int> &dp)
{
    if(index >= s.size()) return 0;

    if(dp.find(index) != dp.end()) return dp[index];

    int ans = s.size() - index;

    string temp = "";

    for(int i = index ; i < s.size(); i++)
    {
        temp+=s[i];

        if(st.find(temp) != st.end())
        {
            ans = min(ans,solve(s,i+1,st,dp));
        }
        else
        {
            int x = temp.size() + solve(s,i+1,st,dp);

            ans = min(ans,x);

            
        }
    }

    // ans = min(ans, 1 + solve(s,index+1,st,dp));

    return dp[index] = ans;
}
public:
    int minExtraChar(string s, vector<string>& dictionary) {

        unordered_map<int,int> dp;

        unordered_set<string> st(dictionary.begin(),dictionary.end());

        return solve(s,0,st,dp);
        
    }
};