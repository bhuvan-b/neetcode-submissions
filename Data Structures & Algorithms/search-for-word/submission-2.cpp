class Solution {
public:
    string track="";
    bool exist(vector<vector<char>>& board, string word) {
        track="";
        vector<vector<bool>> vis(board.size(), vector<bool> (board[0].size(), false));
        for(int i=0;i<board.size();i++)
                for(int j=0;j<board[i].size();j++)
                        if(func(i, j, 0, vis, board, word))
                                return true;
        return false;
    }

    bool func(int indi, int indj, int indw, vector<vector<bool>>& vis, vector<vector<char>>& board, string& word)
    {
        if(indw==word.size())
                return true;
        if(indi<0 || indi>=board.size() || indj<0 || indj>=board[0].size())
                return false;
        if(vis[indi][indj])
                return false;
        if(board[indi][indj] != word[indw])
                return false;
        
        // cout << l << " " << k << ": " <<  board[l][k] << endl;
        vis[indi][indj]=true;
        bool check = func(indi+1, indj, indw+1, vis, board, word) || func(indi-1, indj, indw+1, vis, board, word) || func(indi, indj+1, indw+1, vis, board, word) || func(indi, indj-1, indw+1, vis, board, word);
        if(check)
                return true;
        vis[indi][indj]=false;

        return false;
    }
};

// A B C E
// S F C S
// A D E E
