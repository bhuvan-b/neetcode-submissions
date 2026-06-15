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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> z;
        z.push({p,q});

        while(!z.empty())
        {
            pair<TreeNode*, TreeNode*> tp = z.front();
            z.pop();
            if(!tp.first && !tp.second)
                continue;

            if(!tp.first || !tp.second)
                return false;
            if(tp.first->val!=tp.second->val)
                return false;
            

            z.push({tp.first->left,tp.second->left});
            z.push({tp.first->right,tp.second->right});
        }

        return true;
    }
};
