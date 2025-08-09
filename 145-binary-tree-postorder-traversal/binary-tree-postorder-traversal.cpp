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
    vector<int> postorderTraversal(TreeNode* root) {

        stack<pair<TreeNode*,int>> st;

        if(root == NULL) return {};

        vector<int> ans;

        st.push({root,0});

        while(st.empty() == false)
        {
            TreeNode* curr = st.top().first;
            int turn = st.top().second;
            st.pop();

            if(turn == 0)
            {
                st.push({curr,1});
                if(curr->left != NULL) st.push({curr->left,0});
            }
            else if(turn == 1)
            {
                st.push({curr,2});
                if(curr->right != NULL) st.push({curr->right,0});

            }

            else
            {
                ans.push_back(curr->val);
            }
        }

        return ans;



        
    }
};