class Solution {
public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        dp = vector<vector<int>> (text1.length(), vector<int> (text2.length(), -1));
        return func(0, 0, text1, text2);
    }

    int func(int i1, int i2, string& text1, string& text2)
    {
        if(i1>=text1.length() || i2>=text2.length())
            return 0;

        if(dp[i1][i2]!=-1)
            return dp[i1][i2];

        if(text1[i1]==text2[i2])
            return dp[i1][i2] = 1+func(i1+1, i2+1, text1, text2);

        return dp[i1][i2] = max(func(i1+1, i2, text1, text2), func(i1, i2+1, text1, text2)); 
    }
};
