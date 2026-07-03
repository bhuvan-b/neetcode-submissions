class Solution {
public:
    unordered_map<string, int> mp;
    vector<vector<int>> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        mp = unordered_map<string, int> ();
        dp = vector<vector<int>> (s.length(), vector<int>(s.length()+1, -1));
        for(int i=0;i<wordDict.size();i++)
            mp[wordDict[i]]++;

        return func(0, 1, s);
    }

    bool func(int i, int len, string& s)
    {

        if((i+len)>s.length())
            if(len==1)
                return true;
            else
                return false;

        if(dp[i][len]!=-1)
            return dp[i][len];

        bool cons=false, not_cons=false;

        if(mp.find(s.substr(i, len))!=mp.end())
            cons = func(i+len, 1, s);

        not_cons = func(i, len+1, s);

        return dp[i][len] = cons || not_cons;
        
    }
};
