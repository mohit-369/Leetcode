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
    TreeNode* replaceValueInTree(TreeNode* root) {

        queue<pair<TreeNode*,int>> q;

        q.push({root,0});

        while( q.empty() == false)
        {
            int parent = 0;

            int sum = 0;

            unordered_map<int,int> mpp;

            queue<pair<TreeNode*,int>> q1 = q;

            int size = q.size();

            while(size--)
            {
                TreeNode* curr = q.front().first;

                int p = q.front().second;

                mpp[p] += curr-> val;

                sum += curr -> val;

                q.pop();

                if(curr -> left)
                {
                    q.push({curr -> left, parent});
                }

                if(curr -> right)
                {
                    q.push({curr -> right, parent});
                }

                parent++;
            }

            while( q1.empty() == false )
            {
                TreeNode* curr = q1.front().first;

                int p = q1.front().second;

                q1.pop();

                curr -> val = sum - mpp[p];
            }



            
        }

        return root;
        
    }
};