class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {

        set<string> dic;

        queue<pair<int,string>> q;

        q.push({1,beginWord});

        for(auto &it:wordList)
        {
            dic.insert(it);
        }

        while(q.empty() == false)
        {
            string word = q.front().second;

            int state = q.front().first;

            q.pop();

            if(word == endWord) return state;

            for(int index = 0; index < word.size(); index++)
            {
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    string temp = word;

                    temp[index] = ch;

                    if(dic.find(temp) != dic.end())
                    {
                        q.push({state+1,temp});

                        dic.erase(temp);

                    }
                }
            }


        }

        return 0;
        
    }
};