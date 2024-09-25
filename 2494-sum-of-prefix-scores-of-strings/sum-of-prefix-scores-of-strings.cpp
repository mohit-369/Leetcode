class Solution {
class TrieNode{
    public:
    char ch;
    unordered_map<char,TrieNode*> childs;
    int count;
    TrieNode(char d)
    {
        ch = d;
        count = 0;
    }

};
class Trie{
    TrieNode* root;
    public:
    Trie()
    {
        root = new TrieNode ('\0');
    }

    void insertWord(string word)
    {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++)
        {
            char ch = word[i];

            if(curr -> childs.find(ch) != curr->childs.end())
            {
                curr = curr -> childs[ch];

                curr -> count++;


            }

            else
            {
                TrieNode* newNode = new TrieNode(ch);

                curr -> childs[ch] = newNode;

                curr = newNode;

                curr -> count++;
            }
        }

        return ;
    }

    int count(string word)
    {
        int temp = 0;

        TrieNode* curr = root;

        for(int i = 0; i < word.size(); i++)
        {
            temp += curr -> childs[word[i]] -> count;

            curr = curr -> childs[word[i]];
        }

        return temp;
    }


};
public:
    vector<int> sumPrefixScores(vector<string>& words) {

        Trie* t = new Trie();

        for(auto &it:words)
        {
            t -> insertWord(it);
        }

        

        vector<int> ans;

        for(auto &it:words)
        {
           int temp = t -> count(it);

           ans.push_back(temp);
        }

        return ans;
        
    }
};