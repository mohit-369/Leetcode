class Solution {
    class TrieNode {
    public:
        char ch;
        unordered_map<char, TrieNode*> mpp;
        int count;

        TrieNode(char c) {
            ch = c;
            count = 0;
        }
    };

    class Trie {
        TrieNode *root;
    public:
        Trie() {
            root = new TrieNode('\0');
        }

        void insertWord(string word) {
            TrieNode* curr = root;

            for (int i = 0; i < word.size(); i++) {
                char ch = word[i];

                if (curr->mpp.find(ch) == curr->mpp.end()) {
                    TrieNode* newNode = new TrieNode(ch);
                    curr->mpp[ch] = newNode;
                }
                curr = curr->mpp[ch];
                curr->count++;
            }
        }

        int find(int size) {
            int end = 0;
            TrieNode* curr = root;

            while (curr) {
                TrieNode* temp = nullptr;
                for (char i = 'a'; i <= 'z'; i++) {
                    if (curr->mpp.find(i) != curr->mpp.end() && curr->mpp[i]->count == size) {
                        end++;
                        temp = curr->mpp[i];
                        break;
                    }
                }
                if (temp == nullptr) break; // No more common prefix
                curr = temp;
            }

            return end;
        }
    };

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        Trie* t = new Trie();
        for (auto &it : strs) {
            t->insertWord(it);
        }

        int len = t->find(strs.size());
        return strs[0].substr(0, len);
    }
};
