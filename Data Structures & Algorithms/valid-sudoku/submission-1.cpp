class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0;i<9;i++)
        {
            vector<int> vect(10,0);
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                    continue;
                if(vect[board[i][j]-'0']==1)
                    return false;
                vect[board[i][j]-'0']++;
            }
        }

        for(int i=0;i<9;i++)
        {
            vector<int> vect(10,0);
            for(int j=0;j<9;j++)
            {
                if(board[j][i]=='.')
                    continue;
                if(vect[board[j][i]-'0']==1)
                    return false;
                vect[board[j][i]-'0']++;
            }
        }

        int i=0, j=0;
        while(i<9 && j<9)
        {
            vector<int> vect(10,0);
            for(int k=0;k<3;k++)
            {
                for(int l=0;l<3;l++)
                {
                    if(board[i+k][j+l]=='.')
                        continue;
                    if(vect[board[i+k][j+l]-'0']==1)
                        return false;
                    vect[board[i+k][j+l]-'0']++;
                }
            }
            j+=3;
            if(j>9)
            {
                i+=3;
                j=0;
            }
        }

        return true;

    }
};
