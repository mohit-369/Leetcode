class Solution {
    int solve(int curr, int val, vector<vector<int>> &grid, vector<vector<int>> &dp, string &target) {
        if (curr == target.size()) return 1; 
        if (val == grid[0].size()) return 0; 

        if (dp[curr][val] != -1) return dp[curr][val];

        
        int take = 0;
        if (grid[target[curr] - 'a'][val] > 0) {
            take = ((long long)grid[target[curr] - 'a'][val] * solve(curr + 1, val + 1, grid, dp, target)) % 1000000007;
        }

       
        int notTake = solve(curr, val + 1, grid, dp, target);

       
        return dp[curr][val] = (take + notTake) % 1000000007;
    }

public:
    int numWays(vector<string> &words, string target) {
        int m = target.size(), n = words[0].size();
        vector<vector<int>> grid(26, vector<int>(n, 0));

       
        for (const string &word : words) {
            for (int i = 0; i < n; ++i) {
                grid[word[i] - 'a'][i]++;
            }
        }

       
        vector<vector<int>> dp(m, vector<int>(n, -1));

        
        return solve(0, 0, grid, dp, target);
    }
};
