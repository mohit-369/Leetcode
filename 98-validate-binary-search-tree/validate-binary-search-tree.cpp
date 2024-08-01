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
bool solve(TreeNode* root,long max,long min)
{
    if(root==NULL) return 1;

    if(root->val<=min || root->val>=max)
    {
        return 0;
    }

    bool leftSub=solve(root->left,root->val,min);

    bool rightSub=solve(root->right,max,root->val);

    return leftSub && rightSub;
}
public:
    bool isValidBST(TreeNode* root) {

        return solve(root,LONG_MAX,LONG_MIN);
        
    }
};