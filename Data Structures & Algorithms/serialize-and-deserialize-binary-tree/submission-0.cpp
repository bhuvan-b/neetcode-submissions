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
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* tp = st.top();
            st.pop();
            if(!tp)
            {
                res+="N;";
                continue;
            }
            res+=to_string(tp->val);
            res+=';';
            st.push(tp->right);
            st.push(tp->left);
        }
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // return nullptr;
        return dfs(data);
    }

    TreeNode* dfs(string data)
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
        cout << stoi(tmp) << endl;
        node->left = dfs(data);
        node->right = dfs(data);
        return node;
    }
};

// 1;2;N;N;3;4;N;N;5;N;N;

