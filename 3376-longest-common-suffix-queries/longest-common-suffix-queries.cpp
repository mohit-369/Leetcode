class Solution {
class TrieNode{
    public:
    char data;
    unordered_map<char,TrieNode*> childrens;
    int index;
    int len;
    TrieNode(char data)
    {
        index=INT_MAX;
        len=INT_MAX;
        this->data=data;

    }
};
class Trie{
    public:
    TrieNode* root;
    Trie()
    {
        root=new TrieNode('\0');
    }
};
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {

        int index=0;

        int len=INT_MAX;

        for(int i=0;i<wordsContainer.size();i++)
        {
            if(len>wordsContainer[i].size())
            {
                len=wordsContainer[i].size();
                index=i;
            }
        }

        Trie* t=new Trie();

        TrieNode* curr;

        for(int i=0;i<wordsContainer.size();i++)
        {
            curr=t->root;

            string A=wordsContainer[i];

            reverse(A.begin(),A.end());

            for(auto it:A)
            {
                if(curr->childrens.find(it)==curr->childrens.end())
                {
                    curr->childrens[it]=new TrieNode(it);


                }

                if(A.size()<curr->childrens[it]->len)
                {
                    curr->childrens[it]->len=A.size();

                    curr->childrens[it]->index=i;
                }

                curr=curr->childrens[it];


            }


        }

        vector<int> ans;

        for(auto it:wordsQuery)
        {
            curr=t->root;
            string B=it;

            reverse(B.begin(),B.end());

            int a=index;

            for(auto it:B)
            {
                if(curr->childrens.find(it)==curr->childrens.end()) break;

                a=curr->childrens[it]->index;

                curr=curr->childrens[it];


            }

            ans.push_back(a);
        }

        return ans;
        
    }
};