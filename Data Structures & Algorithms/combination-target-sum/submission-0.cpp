class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int count = 0;
        ans = vector<vector<int>> ();
        vector<int> vect;
        count += func(0, target, nums, 0, vect);
        // cout << count << endl;

        return ans;
    }

    int func(int val, int target, vector<int>& nums, int ind, vector<int> vect)
    {
        if(ind>=nums.size())
                return 0;

        if(val>target)
                return 0;

        if(val==target)
        {
                // for(int i=0;i<vect.size();i++)
                //         cout << vect[i] << " ";
                // cout << endl;
                ans.push_back(vect);
                return 1;
        }
        
        int not_con = func(val, target, nums, ind+1, vect);
        val += nums[ind];
        vect.push_back(nums[ind]);        
        return not_con + func(val, target, nums, ind, vect);
    }
};
