class Solution {
int solve(int id1, int id2, string &word1, string &word2,vector<vector<int>> &dp)
{
    if(id1 < 0 && id2 < 0) return 0;
    if(id1<0) return id2+1;
    if(id2<0) return id1+1;
    if(dp[id1][id2]!=-1) return dp[id1][id2];
    if(word1[id1]==word2[id2])
    {
        return dp[id1][id2]=solve(id1-1,id2-1,word1,word2,dp);
    }

    int del = 1 + solve(id1-1,id2,word1,word2,dp);

    int rep = 1 + solve(id1-1,id2-1,word1,word2,dp);

    int ins = 1 + solve(id1,id2-1,word1,word2,dp);

    return dp[id1][id2]=min({del,rep,ins});
}
public:
    int minDistance(string word1, string word2) {


        int id1 = word1.size()-1;

        int id2 = word2.size()-1;

        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));

        return solve(id1,id2,word1,word2,dp);
        
    }
};