class Solution {
bool check(vector<int> &p,vector<int> &w)
{
    for(int i = 0; i < 26; i++)
    {
        if(p[i] != w[i]) return 0;
    }

    return 1;
}

public:
    bool checkInclusion(string s1, string s2) {

        if(s2.size() < s1.size()) return 0;

        vector<int> p(26,0);

        vector<int> w(26,0);

        for(int i = 0; i < s1.size(); i++)
        {
            p[s1[i] - 'a']++;
        }

        int start = 0;

        int end = 0;

        while(start < s1.size())
        {
            w[s2[start++] - 'a']++;
        }

        

        while(start < s2.size())
        {
            if(check(p,w)) return 1;

            w[s2[start++] - 'a']++;

            w[s2[end++] - 'a']--;

        }

        if(check(p,w)) return 1;

        return 0;


        
    }
};