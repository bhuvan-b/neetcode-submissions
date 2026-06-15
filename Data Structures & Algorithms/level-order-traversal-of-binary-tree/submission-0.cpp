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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root)
            return ans;
            
        vector<TreeNode*> vect;
        vect.push_back(root);

        while(vect.size()>0)
        {
            vector<TreeNode*> level;
            vector<int> leval;
            for(int i=0;i<vect.size();i++)
            {
                TreeNode* it = vect[i];
                leval.push_back(it->val);
                if(it->left)
                    level.push_back(it->left);
                if(it->right)
                    level.push_back(it->right);
            }
            ans.push_back(leval);
            vect=level;
        }

        return ans;
    }
};
