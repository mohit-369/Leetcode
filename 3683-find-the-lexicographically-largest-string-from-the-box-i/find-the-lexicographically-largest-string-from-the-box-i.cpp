class Solution {
public:
    string answerString(string word, int numFriends) {

        int n = word.size();

        int m = n - numFriends + 1;

        if(numFriends == 1) return word;

        string ans;

        for(int i = 0; i < word.size(); i++)
        {
            ans = max(ans,word.substr(i,m));
        }

        return ans;


        
    }
};