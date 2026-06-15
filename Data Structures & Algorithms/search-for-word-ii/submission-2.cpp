class TreeNode {
public:
        vector<TreeNode*> vect;
        bool isEnd = false;
        int index = -1;

        TreeNode()
        {
                vect = vector<TreeNode*> (26, nullptr);
        }
};

void addWord(TreeNode* node, string str, int oid)
{
        if(node==nullptr)
                return;

        for(int i=0;i<str.length();i++)
        {
                int ind = str[i]-'a';
                if(node->vect[ind]==nullptr)
                        node->vect[ind] = new TreeNode();
                
                node = node->vect[ind];
        }
        node->isEnd = true;
        node->index = oid;
}

class Solution {
public:
    unordered_set<string> st;
    vector<int> ans;
    vector<vector<bool>> vis;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ans = vector<int> ();
        vis = vector<vector<bool>> (board.size(), vector<bool> (board[0].size(), false));

        TreeNode* root = new TreeNode();

        for(int i=0;i<words.size();i++)
                addWord(root, words[i], i);

        for(int i=0;i<board.size();i++)
                for(int j=0;j<board[0].size();j++)
                        dfs(i,j,root,board);

        vector<string> fans;
        for(auto it: ans)
        {
                fans.push_back(words[it]);
        }
        return fans;
    }

    void dfs(int l, int k, TreeNode* node, vector<vector<char>>& board)
    {
        if(l<0 || l>=board.size() || k<0 || k>=board[0].size())
                return;

        if(vis[l][k])
                return;

        int cind = board[l][k] - 'a';

        if(node->vect[cind]==nullptr)
                return;

        node = node->vect[cind];

        vis[l][k] = true;

        if(node->isEnd)
        {
                ans.push_back(node->index);
                node->isEnd = false;
        }

        dfs(l+1, k, node, board);
        dfs(l-1, k, node, board);
        dfs(l, k+1, node, board);
        dfs(l, k-1, node, board);

        vis[l][k] = false;

    }

};
