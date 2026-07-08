class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=INT_MIN, currSum=0;
        for(int i=0;i<nums.size();i++)
        {
            currSum += nums[i];
            mx = max(mx, currSum);
            currSum = max(currSum, 0);
        }

        return mx;
    }
};
