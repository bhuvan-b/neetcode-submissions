class Solution {
public:
    vector<int> dp;
    bool canJump(vector<int>& nums) {
        dp = vector<int> (nums.size(), -1);
        return func(0, nums);
    }

    bool func(int i, vector<int>& nums)
    {
        if(i>=nums.size())
            return false;

        if(dp[i]!=-1)
            return dp[i];

        if(i==(nums.size()-1))
            return dp[i] = true;

        for(int j=1;j<=nums[i];j++)
        {
            if(func(i+j, nums))
                return dp[i] = true;
        }

        return dp[i] = false;
    }
};
