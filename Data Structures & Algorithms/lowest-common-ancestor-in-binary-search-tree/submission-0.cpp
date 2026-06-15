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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int l = min(p->val,q->val), r = max(p->val,q->val);

        while(root)
        {
            int m = root->val;
            if(l<=m && r>=m)
                return root;
            if(l<m && r<m)
                root=root->left;
            if(l>m && r>m)
                root=root->right;
        }
        return nullptr;
    }
};
