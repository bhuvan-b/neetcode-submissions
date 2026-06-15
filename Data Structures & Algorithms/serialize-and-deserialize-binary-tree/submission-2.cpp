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

class Codec {
public:
    int ind=0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* tp = q.front();
            q.pop();
            if(!tp)
            {
                res+="N;";
                continue;
            }
            res+=to_string(tp->val);
            res+=';';
            q.push(tp->left);
            q.push(tp->right);
        }
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* node = buildNode(data);
        if(!node)
            return node;
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty())
        {
            TreeNode* tp = q.front();
            q.pop();
            tp->left = buildNode(data);
            if(tp->left)
                q.push(tp->left);
            tp->right = buildNode(data);
            if(tp->right)
                q.push(tp->right);
        }
        return node;
    }

    TreeNode* buildNode(string& data)
    {
        if(ind>=data.length())
            return nullptr;
        if(data[ind]=='N')
        {
            ind+=2;
            return nullptr;
        }
        string tmp="";
        while(data[ind]!=';')
        {
            tmp+=data[ind];
            ind++;
        }
        ind++;
        TreeNode* node = new TreeNode(stoi(tmp));
        return node;
    }
};

// 1;2;N;N;3;4;N;N;5;N;N;

