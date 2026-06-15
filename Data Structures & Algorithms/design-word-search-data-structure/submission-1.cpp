class TreeNode {
        public:
                vector<TreeNode*> vect;
                bool isEnd=false;
                TreeNode()
                {
                        vect = vector<TreeNode*> (26, nullptr);
                }
};

class WordDictionary {
public:
    TreeNode* root;
    WordDictionary() {
        root = new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode* node = root;
        for(int i=0;i<word.length();i++)
        {
                int ind = word[i]-'a';
                if(node->vect[ind]==nullptr)
                {
                        node->vect[ind] = new TreeNode();
                }
                node = node->vect[ind];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TreeNode* node = root;
        return helper(0, node, word);
    }

    bool helper(int ind, TreeNode* node, string word)
    {
        for(int i=ind;i<word.length();i++)
        {
                if(word[i]=='.')
                {
                        for(int j=0;j<26;j++)
                        {
                                // if(node->vect[i] && helper(i+1, node->vect[i], word))
                                //         return true;
                                if(node->vect[j])
                                {
                                        // cout << "alphabet: " << j << endl;
                                        if(helper(i+1, node->vect[j], word))
                                                return true;
                                }
                        }
                        return false;
                }
                int indw = word[i]-'a';
                if(node->vect[indw]==nullptr)
                {
                        // cout << word << " " << word[i] << " here1" << endl;
                        return false;
                }
                node = node->vect[indw];
        }
        if(node->isEnd)
                return true;
        return false;
    }
};
