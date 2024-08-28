class Solution {
int solve(string s1, string s2, int idx1, int idx2,vector<vector<int>> &dp)
{
    // base case

    if(idx1<0 && idx2<0)
    {
        return 0;

    }

    if(idx1<0)
    {
        int result=0;

        for(int i = 0; i<=idx2; i++)
        {
            result+=s2[i];
        }

        return result;
    }

    if(idx2<0)
    {
        int result=0;

        for(int i = 0; i<=idx1; i++)
        {
            result+=s1[i];
        }

        return result;
    }

    if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

    if(s1[idx1] == s2[idx2])
    {
        return dp[idx1][idx2]=solve(s1,s2,idx1-1,idx2-1,dp);
    }

    int leaveFromS1 = s1[idx1]+solve(s1,s2,idx1-1,idx2,dp);

    int leaveFromS2=s2[idx2]+solve(s1,s2,idx1,idx2-1,dp);

    return dp[idx1][idx2]=min(leaveFromS1,leaveFromS2);
}
public:
    int minimumDeleteSum(string s1, string s2) {


        // int idx1 = s1.size()-1;

        // int idx2 = s2.size()-1;

        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));

        for(int row = 1; row <=s1.size(); row++)
        {
            dp[row][0] = s1[row-1]+dp[row-1][0];
        }

        for(int col = 1; col<=s2.size(); col++)
        {
            dp[0][col] = s2[col-1]+dp[0][col-1];
        }

        for(int idx1 = 1; idx1 <=s1.size(); idx1++)
        {
            for(int idx2 =1; idx2<=s2.size(); idx2++)
            {
                if(s1[idx1-1] == s2[idx2-1])
                {
                    dp[idx1][idx2]=dp[idx1-1][idx2-1];
                }

                else
                {
                    int leaveFromS1=s1[idx1-1]+dp[idx1-1][idx2];

                    int leaveFromS2=s2[idx2-1]+dp[idx1][idx2-1];

                    dp[idx1][idx2]=min(leaveFromS1,leaveFromS2);
                }
            }
        }

        return dp[s1.size()][s2.size()];



        
        
    }
};