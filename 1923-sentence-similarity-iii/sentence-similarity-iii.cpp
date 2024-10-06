class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {

        deque<string> q1,q2;

        string word;

        int start = 0;

        while(start < sentence1.size())
        {
            if(sentence1[start] == ' ')
            {
                q1.push_back(word);

                word = "";
            }

            else
            {
                word.push_back(sentence1[start]);
            }

            start++;
        }

        q1.push_back(word);

        word = "";

        start = 0;

        while(start < sentence2.size())
        {
            if(sentence2[start] == ' ')
            {
                q2.push_back(word);

                word = "";
            }

            else
            {
                word.push_back(sentence2[start]);
            }

            start++;
        }

        q2.push_back(word);

        while(q1.size() && q2.size())
        {
            int flag1 = 0, flag2 = 0;

            if(q1.front() == q2.front())
            {
                q1.pop_front();

                q2.pop_front();

                flag1 = 1;
            }

            if(q1.size() == 0 || q2.size() == 0) return 1;

            if(q1.back() == q2.back())
            {
                q1.pop_back();

                q2.pop_back();

                flag2 = 1;


            }

            if(flag1 == 0 && flag2 == 0) return 0;
        }

        return 1;




        
    }
};