class Solution {
int mod = 1e9 + 7;
int solve(int index, int low, int high, int zero, int one, vector<int> &dp)
{
    if(index == high) return 1;

    if(index > high) return 0;

    if(dp[index] != -1) return dp[index];

    long long int ans = 0;

    if(index >= low && index <= high) ans++;

    ans = (ans % mod + solve(index + zero, low, high, zero, one, dp) % mod) % mod;

     ans = (ans % mod + solve(index + one, low, high, zero, one, dp) % mod) % mod;

    return dp[index] = (int)ans;
}
public:
    int countGoodStrings(int low, int high, int zero, int one) {

        vector<int> dp(high + 2,-1);

        return solve(0,low,high,zero,one,dp);
        
    }
};