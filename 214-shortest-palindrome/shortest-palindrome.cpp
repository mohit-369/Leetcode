class Solution {
string rev(string s)
{
    int i = 0;

    int j = s.size() - 1;

    while( i < j)
    {
        swap(s[i++],s[j--]);
    }

    return s;
}
public:
    string shortestPalindrome(string s) {

        string b = rev(s);

        string c = s + '$' + b;

        int size = c.size();

        vector<int> lps(size,0);

        int i = 0;

        int j = 1;

        while(j < size)
        {
            if(c[i] == c[j])
            {
                lps[j] = i + 1;

                i++;

                j++;
            }

            else
            {
                if( i!= 0)
                {
                    i = lps[i - 1];
                }

                else
                {
                    j++;
                }
            }
        }

        int required = s.size() - lps[size - 1];

        string ans;

        int index = s.size() - 1;

        while(required--)
        {
            ans.push_back(s[index--]);
        }

        ans = ans + s;

        return ans;

        
        
    }
};