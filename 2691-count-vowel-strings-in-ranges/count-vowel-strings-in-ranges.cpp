class Solution {
bool check(string words)
{
    int n = words.size() - 1;
    if((words[0] == 'a' || words[0] == 'e' || words[0] == 'i' || words[0] == 'o' || words[0] == 'u') && (words[n] == 'a' || words[n] == 'e' || words[n] == 'i' || words[n] == 'o' || words[n] == 'u') ) return 1;
    return 0;
}
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        vector<int> hash(words.size() + 1,0);

        for(int i = 0; i < words.size(); i++)
        {
            if( i == 0)
            {
                if(check(words[i])) hash[i] = 1;
                else hash[i] = 0;
            }
            else if(check(words[i])) hash[i] = 1 + hash[i-1];
            else hash[i] = hash[i-1];
        }

        vector<int> ans;

        for(auto &it:queries)
        {
            int x = it[0];
            int y = it[1];

            if(x == 0)
            {
                ans.push_back(hash[y]);
            }

            else
            {
                ans.push_back(hash[y] - hash[x-1]);
            }


        }


        return ans;
        
    }
};