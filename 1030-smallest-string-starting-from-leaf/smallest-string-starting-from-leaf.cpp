/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
void solve(TreeNode* root,string &temp,string &small)
{
    if(root==NULL) return ;
    if(root->right==NULL && root->left==NULL)
    {
        char ch=root->val+'a';

        temp.push_back(ch);

        reverse(temp.begin(),temp.end());

        small=min(small,temp);


        reverse(temp.begin(),temp.end());

        temp.pop_back();

        return ;
    }

    char ch=root->val+'a';

    temp.push_back(ch);

    solve(root->left,temp,small);

    solve(root->right,temp,small);

    temp.pop_back();

    return ;
}
public:
    string smallestFromLeaf(TreeNode* root) {

        string small="~";

        string temp;


        solve(root,temp,small);


        return small;
        
    }
};