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
    bool isValidBST(TreeNode* root) {
        int lb=INT_MIN, rb=INT_MAX;
        return isValid(root, lb, rb);
    }

    bool isValid(TreeNode* root, int lb, int rb)
    {
        if(!root)
            return true;
        if(root->val>lb && root->val<rb)
        {
            return isValid(root->left, lb, root->val) && isValid(root->right, root->val, rb);
        }
        return false;
    }
};
