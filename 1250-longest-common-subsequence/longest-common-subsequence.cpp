class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        // vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));

        vector<int> pre(text2.size()+1,0);

        vector<int> curr=pre;



        for(int i = 1; i <= text1.size(); i++)
        {
            for(int j = 1; j <= text2.size(); j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    curr[j] = 1 + pre[j-1];
                }

                else
                {
                    curr[j] = max(curr[j-1],pre[j]);
                }
            }

            pre=curr;
        }

        return pre[text2.size()];
        
    }
};