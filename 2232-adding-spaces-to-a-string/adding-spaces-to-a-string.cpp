class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {

        string ans;

        int index = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(index < spaces.size() && i == spaces[index])
            {
                ans.push_back(' ');
                ans.push_back(s[i]);
                index++;
            }

            else
            {
                ans.push_back(s[i]);
            }
        }

        return ans;


        
    }
};