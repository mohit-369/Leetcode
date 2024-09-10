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

        stack<pair<int,TreeNode*>> st;

        TreeNode* curr = root;

        vector<int> ans;



        while( st.empty() == false || curr != NULL)
        {
            if(curr)
            {
                st.push({0,curr});

                curr = curr -> left;
            }

            else
            {
                TreeNode* node = st.top().second;

                int val = st.top().first;

                st.pop();

                if(val == 0)
                {
                    st.push({1,node});

                    curr = node -> right;
                }

                else
                {
                    ans.push_back(node -> val);
                }
            }
        }

        return ans;
        
    }
};