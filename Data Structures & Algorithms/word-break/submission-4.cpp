class Solution {
public:
    unordered_map<string, int> mp;
    vector<int> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        mp = unordered_map<string, int> ();
        dp = vector<int> (s.length(), -1);
        for(int i=0;i<wordDict.size();i++)
            mp[wordDict[i]]++;

        return func(0, s);
    }

    bool func(int i, string& s)
    {

        if(i>=s.length())
            return true;

        if(dp[i]!=-1)
            return dp[i];

        int len=1;
        bool res = false;
        while((i+len-1)<s.length())
        {
            if(mp.find(s.substr(i, len))!=mp.end())
                res = res || func(i+len, s);
            len++;
        }

        return dp[i] = res;
    }
};
