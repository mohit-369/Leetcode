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
    TreeNode* deleteNode(TreeNode* root, int key) {

        // node point root

        if(root == NULL) return NULL;

        TreeNode* curr = root;

        TreeNode* parent = NULL;

        // prev pointer hoga

        // i will findout my new node its parent

        while( curr != NULL)
        {
            int val = curr -> val;

            if( val == key)
            {
                break;
            }

            else if( val > key)
            {
                parent = curr;

                curr = curr -> left;
            }

            else
            {
                parent = curr;

                curr = curr -> right;
            }
        }

        if(curr == NULL) return root;

        if(parent == NULL)
        {
            TreeNode* temp = curr -> right;

            if(temp == NULL) 
            {
                parent = curr;

                curr = curr -> left;

                parent -> left = NULL;

                return curr;
            }

            while( temp -> left)
            {
                temp = temp -> left;
            }

            temp -> left = curr -> left;

            parent = curr;

            curr = curr -> right;

            parent -> left = NULL;

            parent -> right = NULL;

            return curr;


        }

        else
        {

            TreeNode* temp = curr -> right;

            if(temp == NULL)
            {
                if(parent -> left == curr)
                {
                    parent -> left = curr -> left;

                    curr -> left = NULL;

                    return root;
                }

                else
                {
                    parent -> right = curr -> left;

                    curr -> left = NULL;

                    return root;
                }
            }

            while(temp -> left)
            {
                temp = temp -> left;
            }

            if(parent -> left == curr)
            {
                parent -> left = curr -> right;

                temp -> left = curr -> left;

                curr -> left = NULL;

                curr -> right = NULL;

                return root;
            }

            else
            {
                parent -> right = curr -> right;

                temp -> left = curr -> left;

                curr -> left = NULL;

                curr -> right = NULL;

                return root;
            }

        }

        return root;
        
    }
};