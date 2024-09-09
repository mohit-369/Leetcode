class Solution {
int solve(char ch, string &s, int k)
{
    int len = INT_MIN;

    int start = 0;

    int end = 0;

    while(end < s.size())
    {
        if(ch!=s[end]) k--;

        while(k<0)
        {
            if(s[start]!=ch) k++;

            start++;
        }

        len = max(len,end-start+1);

        end++;
    }

    return len;


}
public:
    int characterReplacement(string s, int k) {


        int ans = INT_MIN;

        for(char ch = 'A'; ch<='Z'; ch++)
        {
            ans = max(ans,solve(ch,s,k));
        }

        return ans;
        
    }
};