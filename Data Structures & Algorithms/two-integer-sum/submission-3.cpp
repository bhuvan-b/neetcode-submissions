class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++)
        {
            auto it = mp.find(target-nums[i]);
            if(it != mp.end())
            {
                return {min(it->second, i), max(it->second, i)};
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return {};
    }
};
