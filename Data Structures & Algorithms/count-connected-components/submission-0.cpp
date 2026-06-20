class Solution {
public:
    vector<bool> vis;
    unordered_map<int, vector<int>> mp;
    int countComponents(int n, vector<vector<int>>& edges) {
        vis = vector<bool> (n, false);
        mp = unordered_map<int, vector<int>> ();

        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }

        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
                cnt++;
            }
        }

        return cnt;

    }

    void dfs(int val)
    {
        if(vis[val])
            return;

        vis[val] = true;

        for(int i=0;i<mp[val].size();i++)
        {
            dfs(mp[val][i]);
        }
    }
};
