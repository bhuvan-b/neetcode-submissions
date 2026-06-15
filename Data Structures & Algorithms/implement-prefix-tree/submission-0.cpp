struct TreeNode {
    char val;
    bool isEnd=false;
    vector<TreeNode*> vect = vector<TreeNode*>(26, nullptr);
    TreeNode() : val('#') {}
    TreeNode(char x) : val(x) {}
};

class PrefixTree {
public:
    TreeNode* root;
    PrefixTree() { 
        root = new TreeNode();       
    }
    
    void insert(string word) {
        TreeNode* node = root;
        for(int i=0;i<word.length();i++)
        {
                int ind = word[i]-'a';
                if((node->vect)[ind]==nullptr)
                {
                        (node->vect)[ind] = new TreeNode(word[i]);
                }
                node = (node->vect)[ind];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TreeNode* node = root;
        for(int i=0;i<word.length();i++)
        {
                int ind = word[i]-'a';
                if((node->vect)[ind]==nullptr)
                        return false;
                node = (node->vect)[ind];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TreeNode* node = root;
        for(int i=0;i<prefix.length();i++)
        {
                int ind = prefix[i]-'a';
                if((node->vect)[ind]==nullptr)
                        return false;
                node = (node->vect)[ind];
        }
        return true;
    }
};
