class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<bool>> vis(matrix.size(), vector<bool> (matrix[0].size(), false));

        int i=0, j=0;
        char dir = 'r';
        unordered_map<char, pair<int, int>> mp;

        mp['r'] = {0, 1};
        mp['d'] = {1, 0};
        mp['l'] = {0, -1};
        mp['u'] = {-1, 0};

        vector<int> ans;
        pair<int, int> lastPos = {-1, -1};
        int cnt=0;

        while(!vis[i][j])
        {
            if((i+mp[dir].first >= matrix.size()) || (i+mp[dir].first < 0) || (j+mp[dir].second >= matrix[0].size()) || (j+mp[dir].second < 0) || vis[i+mp[dir].first][j+mp[dir].second])
            {
                dir = chdir(dir);
                if(make_pair(i,j)!=lastPos)
                    cnt=0;
                lastPos = {i,j};
                cnt++;
                if(cnt==4)
                    break;
                continue;
            }
            ans.push_back(matrix[i][j]);
            vis[i][j] = true;
            i+=mp[dir].first;
            j+=mp[dir].second;
        }
        ans.push_back(matrix[i][j]);
        return ans;
    }

    char chdir(char ch)
    {
        if(ch=='r')
            return 'd';
        if(ch=='d')
            return 'l';
        if(ch=='l')
            return 'u';
        if(ch=='u')
            return 'r';

        return 'x';
    }

};

// change direction if hit boundary (keep visited matrix)
// change direction based on current direction
 