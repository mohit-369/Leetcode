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
void solve(TreeNode* root,int k,int &index,int &ans)
{
    if(root==NULL) return ;

    solve(root->left,k,index,ans);

    index++;

    if(index==k)
    {
        ans=root->val;
    }

    solve(root->right,k,index,ans);
}
public:
    int kthSmallest(TreeNode* root, int k) {

        int ans=-1;

        int index=0;

        solve(root,k,index,ans);

        return ans;


        
    }
};