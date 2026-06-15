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
    int maxPathSum(TreeNode* root) {

        int mx = root->val;
        mx = max(mx, maxFunc(mx, root));
        return mx;
    }

    int maxFunc(int &mx, TreeNode* root)
    {
        if(!root)
            return 0;

        int left = maxFunc(mx, root->left);
        int right = maxFunc(mx, root->right);
        mx = max(mx, max({left, right, 0})+root->val);
        mx = max(mx, left+right+root->val);
        return max({left, right,0})+root->val;
    }
};
 
