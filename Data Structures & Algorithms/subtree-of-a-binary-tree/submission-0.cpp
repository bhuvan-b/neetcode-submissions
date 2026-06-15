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

    bool check(TreeNode* node, TreeNode* subnode)
    {
        if(!node && !subnode)
            return true;
        if(!node || !subnode)
            return false;
        if(node->val!=subnode->val)
            return false;
        return check(node->left, subnode->left) && check(node->right , subnode->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
            
        if(root->val==subRoot->val)
            if(check(root, subRoot))
                return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }
};
