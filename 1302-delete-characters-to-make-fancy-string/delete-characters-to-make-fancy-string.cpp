class Solution {
public:
    string makeFancyString(string s) {

        string ans;

        int start = 0;

        while(start < s.size())
        {
            int tail = start + 1;

            ans.push_back(s[start]);

            while(tail < s.size() && s[start] == s[tail])
            {
                tail++;
            }

            int size = tail - start;

            if(size >= 2)
            {
                ans.push_back(s[start]);
            }

            start = tail;

        }

        return ans;
        
    }
};