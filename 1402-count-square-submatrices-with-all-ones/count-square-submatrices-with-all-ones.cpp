class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int ans = 0;

        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(), 0));

        for(int i = 0; i < matrix[0].size(); i++)
        {
            if(matrix[0][i]) dp[0][i] = 1;
        }

        for(int i = 0; i < matrix.size(); i++)
        {
            if(matrix[i][0]) dp[i][0] = 1;
        }

        for(int i = 1; i < matrix.size(); i++)
        {
            for(int j = 1; j < matrix[0].size(); j++)
            {
                if(matrix[i][j])
                {
                    dp[i][j] = 1 + min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                }
            }
        }

        for(int i = 0; i < dp.size(); i++)
        {
            for(int j = 0; j < dp[0].size(); j++)
            {
                ans += dp[i][j];
            }
        }

        return ans;
        
    }
};