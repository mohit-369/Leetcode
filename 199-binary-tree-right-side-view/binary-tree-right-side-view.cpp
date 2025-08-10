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
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        if(root == NULL) return ans;

        queue<pair<TreeNode*,int>> q;

        q.push({root,0});

        map<int,int> mpp;

        while(q.empty() == false)
        {
            TreeNode* curr = q.front().first;

            int val = q.front().second;

            q.pop();

            if(mpp.find(val) == mpp.end())
            {
                mpp[val] = curr->val; 
            }

            if(curr->right != NULL) q.push({curr->right,val+1});
            if(curr->left != NULL) q.push({curr->left,val+1}); 
        }

        for(auto &[key,val]:mpp)
        {
            ans.push_back(val);
        }

        return ans;
        
    }
};