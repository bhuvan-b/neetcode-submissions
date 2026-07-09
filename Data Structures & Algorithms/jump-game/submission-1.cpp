class Solution {
public:
    vector<bool> dp;
    bool canJump(vector<int>& nums) {
        dp = vector<bool> (nums.size(), false);
        dp[nums.size()-1] = true;

        for(int i=nums.size()-2;i>=0;i--)
            for(int j=1;j<=(min((int)nums.size()-i-1, nums[i]));j++)
                if(dp[i+j])
                    dp[i] = true;
     
        return dp[0];
    }
};
