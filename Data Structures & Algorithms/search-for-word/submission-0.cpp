class Solution {
public:
    string track="";
    bool exist(vector<vector<char>>& board, string word) {
        track="";
        vector<vector<bool>> vis(board.size(), vector<bool> (board[0].size(), false));
        for(int i=0;i<board.size();i++)
        {
                for(int j=0;j<board[i].size();j++)
                {
                        if(board[i][j]==word[0])
                        {
                                vis[i][j] = true;
                                track.push_back(board[i][j]);
                                if(func(i,j,vis, board, word))
                                {
                                        cout << i << " " << j << endl;
                                        return true;
                                }
                                track.pop_back();
                                vis[i][j] = false;
                        }
                }
        }
        return false;
    }

    bool func(int indi, int indj, vector<vector<bool>>& vis, vector<vector<char>>& board, string& word)
    {
        if(track==word)
                return true;

        if(track.length()>=word.length())
                return false;

        for(int i=-1;i<=1;i++)
        {
                for(int j=-1;j<=1;j++)
                {
                        int l=indi+i;
                        int k=indj+j;
                        if(i!=0)
                        {
                                k=indj;
                        }
                        if(j!=0)
                        {
                                l=indi;
                        }

                        if(l>=0 && l<board.size() && k>=0 && k<board[0].size())
                        {
                                if(!vis[l][k])
                                {
                                        cout << l << " " << k << ": " <<  board[l][k] << endl;
                                        vis[l][k]=true;
                                        track.push_back(board[l][k]);
                                        if(func(l, k, vis, board, word))
                                                return true;
                                        track.pop_back();
                                        vis[l][k]=false;
                                }
                        }
                }
        }

        return false;
    }
};
