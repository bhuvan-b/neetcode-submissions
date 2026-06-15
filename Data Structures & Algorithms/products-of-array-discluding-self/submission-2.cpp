class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);
        int right=1;

        for(int i=1;i<res.size();i++)
            res[i] = res[i-1]*nums[i-1];

        for(int i=res.size()-2;i>=0;i--)
        {
            right=right*nums[i+1];
            res[i] = res[i]*right;
        }

        return res;
    }
};
