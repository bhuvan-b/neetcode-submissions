class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int gMin = nums[0], gMax = nums[0], currMax = nums[0], ans=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            int tmp = gMax*nums[i];
            gMax = max({nums[i], gMax*nums[i], gMin*nums[i]});
            gMin = min({nums[i], tmp, gMin*nums[i]});
            ans = max({ans, gMin, gMax});
        }
        // ans = max({gMin, gMax, currMax});
        return ans;
    }
};
// -5 2 4 7 