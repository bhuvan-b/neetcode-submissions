class Solution {
public:
    vector<int> dp;
    int lengthOfLIS(vector<int>& nums) {
        dp = vector<int> (nums.size(), -1);
        int ans = 0;
        for(int i=0;i<nums.size();i++)
            ans = max(ans, func(i, nums));

        return ans;
    }

    int func(int i, vector<int>& nums)
    {
        if(i>=nums.size())
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        int pick=1;
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]>nums[i])
                pick = max(pick, 1 + func(j, nums));
        }
        return dp[i] = pick;
    }
};
