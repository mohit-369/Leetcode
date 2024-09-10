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
    int diameterOfBinaryTree(TreeNode* root) {

        stack<pair<int,TreeNode*>> st;

        int diameter = 0;

        unordered_map<TreeNode*,int> mpp;

        mpp[NULL] = 0;

        TreeNode* curr = root;

        while( st.empty() == false || curr != NULL)
        {
            if(curr != NULL)
            {
                st.push({0,curr});
                curr = curr -> left;

            }

            else
            {
                TreeNode* node = st.top().second;

                int turn = st.top().first;

                st.pop();

                if( turn == 0)
                {
                    st.push({1,node});

                    curr = node -> right;
                }

                else
                {
                    diameter = max(diameter,mpp[node -> left] + mpp[node -> right]);

                    mpp[node] = 1 + max(mpp[node -> left],mpp[node -> right]);
                }
            }
        }

        return diameter;
        
    }
};