class Solution {
public:
    vector<vector<int>> dp;
    int lengthOfLIS(vector<int>& nums) {
        dp = vector<vector<int>> (nums.size(), vector<int> (nums.size(), -1));
        return func(0, -1, nums);
    }

    int func(int i, int prev, vector<int>& nums)
    {
        if(i>=nums.size())
            return 0;

        if(prev!=-1 && dp[i][prev]!=-1)
            return dp[i][prev];

        int pick=0, not_pick=0;
        if(prev == -1 || nums[i]>nums[prev])
            pick = 1 + func(i+1, i, nums);

        not_pick = func(i+1, prev, nums);

        if(prev==-1)
            return max(pick, not_pick);
        return dp[i][prev] = max(pick, not_pick);
    }
};
