class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0, r=0;
        vector<int> ans;
        map<int, int> mp;

        while(l<=r && r<nums.size())
        {
            mp[nums[r]]++;
            if(r-l+1==k)
            {
                auto it = mp.rbegin();
                ans.push_back(it->first);
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
            r++;
        }

        return ans;
    }
};
