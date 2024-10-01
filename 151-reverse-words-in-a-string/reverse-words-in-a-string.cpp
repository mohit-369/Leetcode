class Solution {
void rev(string &s, int st, int ed)
{
    while(st < ed)
    {
        swap(s[st++],s[ed--]);
    }

    return ;
}
public:
    string reverseWords(string s) {

        reverse(s.begin(),s.end());

        int i = 0;

        int start = 0;

        string ans;

        while(i < s.size())
        {

            if(s[i] != ' ')
            {
                start = i;

                while( i < s.size() && s[i] != ' ')
                {
                    i++;
                }

                rev(s,start,i-1);

                ans = ans + s.substr(start,i - start) + " ";
            }
            else
            {
                i++;
            }
        }

        ans.pop_back();

        return ans;
        
    }
};