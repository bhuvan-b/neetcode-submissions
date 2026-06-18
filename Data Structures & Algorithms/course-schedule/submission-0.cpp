class Node {
public:
    int val;
    vector<Node*> nds;

    Node(int num)
    {
        val = num;
    }
};

class Solution {
public:
    vector<bool> vis, trk;
    unordered_map<int, vector<int>> mp;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        mp = unordered_map<int, vector<int>> ();

        for(int i=0;i<prerequisites.size();i++)
        {
                mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vis = vector<bool> (numCourses, false);
        trk = vector<bool> (numCourses, false);

        for(int i=0;i<numCourses;i++)
        {
                if(!dfs(i))
                        return false;
        }

        return true;
    }

    bool dfs(int l)
    {
        if(trk[l])
                return false;
        if(vis[l])
                return true;

        vis[l] = true;
        trk[l] = true;

        for(int i=0;i<mp[l].size();i++)
        {
                int num = mp[l][i];
                if(!dfs(num))
                        return false;
        }

        trk[l] = false;

        return true;
    }
};

// 0 -> 1
// 1 -> 
// 2 -> 3, 4
// 3 ->
// 4 -> 5
// 5
// 6 

// 0 -> 1
// 1 -> 
// 2 -> 3, 4
// 3 ->
// 4 -> 3, 5
// 5 -> 2
// 6 

// 0 -> 1
// 1 -> 
// 2 -> 3, 4
// 3 ->
// 4 -> 3, 5
// 5 -> 4
// 6 

