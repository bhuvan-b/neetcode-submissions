class Solution {
public:
    vector<int> dp;
    int numDecodings(string s) {
        dp = vector<int> (s.length(), -1);
        return func(0, s);
    }

    int func(int i, string &s)
    {
        if(i>=s.length())
        {
            return 1;
        }

        if(s[i]=='0')
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        string st = s.substr(i, 1);
        int call1 = func(i+1, s);
        int call2 = 0;
        if(i+1<s.length())
        {
            if(stoi(s.substr(i, 2))<=26)
                call2 = func(i+2, s);
        }

        return dp[i] = call1 + call2;
        // return func(i+1, 1, s) + func(i, 2, s);
    }
};


// 1224819

