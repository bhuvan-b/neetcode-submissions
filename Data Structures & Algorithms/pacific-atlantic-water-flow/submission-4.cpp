class Solution {
public:
    vector<vector<int>> hts;
    vector<vector<bool>> vis; 
    vector<vector<char>> dp;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        hts = heights;
        vis = vector<vector<bool>> (heights.size(), vector<bool> (heights[0].size(), false));
        vector<vector<bool>> pac(heights.size(), vector<bool> (heights[0].size(), false));
        vector<vector<bool>> atl(heights.size(), vector<bool> (heights[0].size(), false));

        for(int i=0;i<heights.size();i++)
        {
                dfs(i,0,INT_MIN,pac);
        }
        for(int i=0;i<heights[0].size();i++)
        {
                dfs(0,i,INT_MIN,pac);
        }
        for(int i=0;i<heights.size();i++)
        {
                dfs(i,heights[0].size()-1,INT_MIN,atl);
        }
        for(int i=0;i<heights[0].size();i++)
        {
                dfs(heights.size()-1,i,INT_MIN,atl);
        }

        for(int i=0;i<heights.size();i++)
        {
                for(int j=0;j<heights[0].size();j++)
                {
                        if(pac[i][j] && atl[i][j])
                                ans.push_back({i,j});
                }
        }

        return ans;
    }

    void dfs(int l, int k, int curr, vector<vector<bool>> &ocn)
    {
        if(l<0 || k<0)
                return;

        if(l>=hts.size() || k>=hts[0].size())
                return;

        if(hts[l][k]<curr)
                return;

        if(ocn[l][k])
                return;

        // vis[l][k] = true;

        ocn[l][k] = true;

        dfs(l, k-1, hts[l][k], ocn);
        dfs(l, k+1, hts[l][k], ocn);
        dfs(l-1, k, hts[l][k], ocn);
        dfs(l+1, k, hts[l][k], ocn);

        // vis[l][k] = false;

        return;
    }
};
