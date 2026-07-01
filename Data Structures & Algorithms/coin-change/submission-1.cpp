class Solution {
public:
    vector<vector<int>> dp;
    int coinChange(vector<int>& coins, int amount) {
        dp = vector<vector<int>> (amount+1, vector<int> (coins.size(), -2));
        return func(0, amount, coins);
    }

    int func(int ind, int amount, vector<int>& coins)
    {
        if(amount==0)
            return 0;
        
        if(ind>=coins.size())
            return -1;    

        if(amount<0)
            return -1;

        if(dp[amount][ind]!=-2)
            return dp[amount][ind];

        int res1 = func(ind, amount-coins[ind], coins);
        int res2 = func(ind+1, amount, coins);

        if(res1==-1 && res2==-1)
            return -1;
        if(res1==-1)
            return dp[amount][ind] = res2;
        if(res2==-1)
            return dp[amount][ind] = 1+res1;

        return dp[amount][ind] = min(1+res1, res2);
    }
};


// 9 5 4 1