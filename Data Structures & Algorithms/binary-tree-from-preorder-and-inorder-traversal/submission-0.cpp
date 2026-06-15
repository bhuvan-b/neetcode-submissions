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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }

        return build(mp, preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* build(unordered_map<int, int>& mp, vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right)
    {
        if(pre_right-pre_left<0)
            return nullptr;
        if(in_right-in_left<0)
            return nullptr;
        int ind = mp[preorder[pre_left]];
        TreeNode* rootNode = new TreeNode(preorder[pre_left]);
        rootNode->left = build(mp, preorder, inorder, pre_left+1, pre_left+ind-in_left, in_left, ind-1);
        rootNode->right = build(mp, preorder, inorder, pre_left+ind-in_left+1, pre_right, ind+1, in_right);
        return rootNode;
    }


};

//             7
//     4               10
// 2       6       8         11
//   3

// preorder -> 7 4 2 3 6 10 8 11

// inorder -> 2 3 4 6 7 8 10 11


// Step 1:
// pre - 7 - ind=4 
// 4 2 3 6 10 8 11
// left = i+1, i+ind
// right = i+ind+1, end

// 2 3 4 6 
// 7 
// 8 10 11
// left = i, ind-1
// right = ind+1, end

// Step 2:
// pre = 4 2 3 6
// inord = 2 3 4 6


