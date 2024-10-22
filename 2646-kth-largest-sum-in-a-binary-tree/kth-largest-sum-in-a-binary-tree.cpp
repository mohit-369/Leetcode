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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        queue<TreeNode*> q;

        q.push(root);

        int level = 0;

        vector<long long > sum;

        while( q.empty() == false)
        {
            

            
                int levelSize = q.size();

                long long ans = 0;

                

                while(levelSize--)
                {
                    TreeNode* curr = q.front();

                    ans += (curr-> val)*1ll;

                    q.pop();

                    if(curr -> left) q.push(curr -> left);

                    if(curr -> right) q.push(curr -> right);


                }

                sum.push_back(ans);
            
        }

        auto cmp = [&](long long a, long long b)
        {
            return a > b;
        };

        sort(sum.begin(),sum.end(),cmp);

        

        for(int i = 0; i < sum.size(); i++)
        {
            if( i + 1 == k) return sum[i];
        }

        return -1;
        

        
    }
};