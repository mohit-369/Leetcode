class Solution {
    int solve(const string &s, int index, const unordered_set<string> &st, unordered_map<int, int> &dp) {
        if (index >= s.size()) return 0; // base case

        if (dp.find(index) != dp.end()) return dp[index]; // memoization check

        int ans = s.size() - index; // worst case: all remaining characters are extra

        string temp = "";
        for (int i = index; i < s.size(); i++) {
            temp += s[i]; // build substring

            if (st.find(temp) != st.end()) {
                // No extra characters for this substring, move to the next part
                ans = min(ans, solve(s, i + 1, st, dp));
            } else {
                // Count current characters as extra
                int extra = temp.size() + solve(s, i + 1, st, dp);
                ans = min(ans, extra);
            }
        }

        return dp[index] = ans; // store the result
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end()); // convert dictionary to set
        unordered_map<int, int> dp; // memoization map

        return solve(s, 0, st, dp); // start from index 0
    }
};
