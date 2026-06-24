class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        dp = vector<int> (nums.size(), -1);
        return func(0, nums);
    }

    int func(int i, vector<int>& nums)
    {
        if(i>=nums.size())
            return 0;

        if(dp[i]!=-1)
            return dp[i];
        return dp[i] = max(nums[i] + func(i+2, nums), func(i+1, nums));
    }
};
