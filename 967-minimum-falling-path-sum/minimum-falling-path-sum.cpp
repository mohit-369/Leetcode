class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        vector<int> dp;

        for(int i = 0; i < matrix[0].size(); i++)
        {
            dp.push_back(matrix[0][i]);
        }

        for(int row = 1; row < matrix.size(); row++)
        {
            vector<int> temp;
            for(int col = 0; col < matrix[0].size(); col++)
            {
                int up = dp[col];

                int diagonaleft = (col - 1 >= 0) ? dp[col - 1] : INT_MAX;

                int diagonalright = (col + 1 < matrix[0].size()) ? dp[col + 1] :INT_MAX;

                int mini = matrix[row][col] + min({up,diagonaleft,diagonalright});

                temp.push_back(mini);

            }

            dp = temp;
        }

        return *min_element(dp.begin(),dp.end());


    
        
    }
};