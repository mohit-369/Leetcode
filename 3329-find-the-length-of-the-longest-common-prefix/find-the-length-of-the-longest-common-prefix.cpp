class Solution {
class TrieNode{
    public:
    char ch;
    bool isterminated;
    unordered_map<char,TrieNode*> childs;
    TrieNode( char x)
    {
        ch = x;
        isterminated = false;
    }
};
class Trie{
    TrieNode* root;

    public:

    Trie()
    {
        root = new TrieNode('/0');
    }

    void insert(string word)
    {
        TrieNode* curr = root;

        for(int index = 0; index < word.size(); index++)
        {
            char ch = word[index];

            if(curr -> childs.find(ch) == curr -> childs.end())
            {
                TrieNode* newNode = new TrieNode(ch);

                curr -> childs[ch] = newNode;

                curr = newNode;
            }

            else
            {
                curr = curr -> childs[ch];
            }


        }

        curr -> isterminated = true;


    }

    int longestPrefix(string word)
    {
        int len = 0;

        TrieNode* curr = root;

        for(int index = 0; index < word.size(); index++)
        {
            if(curr -> childs.find(word[index]) != curr -> childs.end())
            {
                len++;
                curr = curr -> childs[word[index]];
            }

            else
            {
                break;
            }
        }

        return len;
    }

};
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        Trie* t = new Trie();

        for(auto &it:arr1)
        {
            string temp = to_string(it);

            t -> insert(temp);

        }

        int ans = 0;

        for(auto &it:arr2)
        {
            string temp = to_string(it);

            ans = max(ans,t->longestPrefix(temp));
        }

        return ans;
        
    }
};