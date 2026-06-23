class Solution {
public:
    vector<int> dp;
    int climbStairs(int n) {
        dp = vector<int> (n+1, 0);
        return func(n);
    }

    int func(int n)
    {
        if(n<0)
            return 0;
        if(n==0)
            return 1;

        if(dp[n])
            return dp[n];

        return dp[n] = func(n-1) + func(n-2);
    }
};
