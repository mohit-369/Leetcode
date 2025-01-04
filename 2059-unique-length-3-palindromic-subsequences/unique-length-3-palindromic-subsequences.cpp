class Solution {
public:
    int countPalindromicSubsequence(string s) {

        set<string> st;

        vector<vector<int>> track(26);

        for(int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'a';

            if(track[idx].size() == 0 || track[idx].size() == 1)
            {
                track[idx].push_back(i);
            }

            else
            {
                track[idx].pop_back();
                track[idx].push_back(i);
            }
        }

        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 0; j < 26; j++)
            {
                if(track[j].size() == 2)
                {
                    int x = track[j][0];
                    int y = track[j][1];

                    if(i > x && i < y)
                    {
                        string temp;
                        temp.push_back(s[x]);
                        temp.push_back(s[i]);
                        temp.push_back(s[y]);
                        st.insert(temp);
                    }

                }
            }
        }


        return st.size();
        
    }
};