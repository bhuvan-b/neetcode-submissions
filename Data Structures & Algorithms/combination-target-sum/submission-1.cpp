class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int count = 0;
        ans = vector<vector<int>> ();
        vector<int> vect;
        func(0, target, nums, 0, vect);
        
        return ans;
    }

    void func(int val, int target, vector<int>& nums, int ind, vector<int>& vect)
    {
        if(ind>=nums.size())
                return;
        if(val>target)
                return;

        if(val==target)
        {
                ans.push_back(vect);
                return;
        }

        for(int i=ind;i<nums.size();i++)
        {
                vect.push_back(nums[i]);
                func(val+nums[i], target, nums, i, vect);
                vect.pop_back();
        }
    }
};
