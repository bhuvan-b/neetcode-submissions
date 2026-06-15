class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i=0;i<grid.size();i++)
        {
                for(int j=0;j<grid[0].size();j++)
                {
                        if(grid[i][j]=='1')
                        {
                                cnt++;
                                dfs(i,j, grid);
                        }
                }
        }

        return cnt;
    }

    void dfs(int l, int k, vector<vector<char>>& grid)
    {
        if(l<0 || l>=grid.size() || k<0 || k>=grid[0].size())
                return;

        if(grid[l][k]=='0')
                return;

        grid[l][k] = '0';

        dfs(l+1, k, grid);
        dfs(l-1, k, grid);
        dfs(l, k+1, grid);
        dfs(l, k-1, grid);

    }
};
