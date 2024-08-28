class Solution {
public:
    string longestPalindrome(string s) {

        string ans;

        int len = 0;

        vector<vector<int>> dp(s.size(),vector<int> (s.size(),0));

        for(int gap = 0; gap < s.size(); gap++)
        {
            for(int start = 0; start < s.size()-gap; start++)
            {
                if(gap==0)
                {
                    dp[start][gap+start]=1;

                    if(len<(gap+1))
                    {
                        len=gap+1;

                        ans = s.substr(start,gap+1);
                    }

                }

                else if(gap==1)
                {
                    if(s[start]==s[start+gap])
                    {
                        dp[start][gap+start]=1;

                        if(len<(gap+1))
                        {
                            len=gap+1;

                            ans=s.substr(start,gap+1);
                        }
                    }
                }

                else
                {
                    if(s[start]==s[start+gap])
                    {
                        dp[start][start+gap]=dp[start+1][start+gap-1];

                        if(dp[start][start+gap] && len<(gap+1))
                        {
                            len=gap+1;

                            ans=s.substr(start,gap+1);
                        }
                    }
                }


            }
        }

        return ans;
        
    }
};