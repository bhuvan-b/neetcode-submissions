class Solution {
public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        dp = vector<vector<int>> (text1.length()+1, vector<int> (text2.length()+1, 0));

        for(int i1=text1.length()-1;i1>=0;i1--)
            for(int i2=text2.length()-1;i2>=0;i2--)
                if(text1[i1]==text2[i2])
                    dp[i1][i2] = 1 + dp[i1+1][i2+1];
                else
                    dp[i1][i2] = max(dp[i1+1][i2], dp[i1][i2+1]);

        return dp[0][0];
    }
};
