class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans = 0;

        stringstream ss(sentence);

        string word;

        while(ss >> word)
        {
            if(searchWord.size() <= word.size())
            {
                int flag = 1;

                for(int i = 0; i < searchWord.size(); i++)
                {
                    if( searchWord[i] != word[i])
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag) return ans + 1;


            }

            ans++;


        }

        return -1;


    }
};