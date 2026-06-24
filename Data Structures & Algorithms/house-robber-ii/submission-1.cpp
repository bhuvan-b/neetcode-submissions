class Solution {
public:
    vector<vector<int>> dp;
    int rob(vector<int>& nums) {
        dp = vector<vector<int>> (nums.size(), vector<int> (2,-1));
        return func(0, nums, false);
    }

    int func(int i, vector<int>& nums, bool bl)
    {
        if(i>=nums.size())
            return 0;

        if(dp[i][bl]!=-1)
            return dp[i][bl];

        if((i==(nums.size()-1)) && bl)
            return 0;

        bool pick = bl || i==0;

        int con = nums[i] + func(i+2, nums, pick);

        int not_con = func(i+1, nums, bl);
        return dp[i][pick] = max(con, not_con);
    }
};
