class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        dp = vector<int> (nums.size()+1, 0);
        // dp[nums.size()] = 0;

        for(int i=nums.size()-1;i>=0;i--)
        {
            int con = nums[i], not_con = 0;
            if((i+2)<=nums.size())
                con += dp[i+2];
            not_con = dp[i+1];
            
            dp[i] = max(con, not_con);
        }
        return dp[0];
    }

};
