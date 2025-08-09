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
int solve(TreeNode* &root, int &ans)
{
    if(root == NULL) return 0;

    int left = solve(root->left,ans);
    int right = solve(root->right,ans);
    if(left < 0) left = 0;
    if(right < 0) right = 0;
    ans = max({ans,left+right+root->val});

    return root->val + max(left,right);
}
public:
    int maxPathSum(TreeNode* root) {

        int ans = INT_MIN;

        solve(root,ans);

        return ans;




        
    }
};