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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vect;
        dfs(root, &vect);
        return vect[k-1];
    }

    void dfs(TreeNode* node, vector<int>* vect)
    {
        if(!node)
            return;
        dfs(node->left, vect);
        (*vect).push_back(node->val);
        dfs(node->right, vect);
    }
};