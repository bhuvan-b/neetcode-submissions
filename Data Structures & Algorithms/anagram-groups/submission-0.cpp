class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;

        for(int i=0;i<strs.size();i++)
        {
            vector<int> vect(26, 0);
            for(int j=0;j<strs[i].length();j++)
            {
                vect[strs[i][j]-'a']++;
            }
            mp[vect].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};
