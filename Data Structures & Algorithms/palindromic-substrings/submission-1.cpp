class Solution {
public:
    int countSubstrings(string s) {
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                if(ispal(i,j, s))
                    cnt++;
            }
        }
        return cnt;
    }

    bool ispal(int l, int r, string& s)
    {
        if(l>=r)
            return true;

        // if(dp[l][r]!=-1)
        //     return dp[l][r];

        if(s[l]!=s[r])
            return false;
            // return dp[l][r] = false;

        return ispal(l+1, r-1, s);
    }
};