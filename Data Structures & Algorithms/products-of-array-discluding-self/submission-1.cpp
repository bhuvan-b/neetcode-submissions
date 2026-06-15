class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> vect1(nums.size(), 1), vect2(nums.size(), 1);

        for(int i=1;i<vect1.size();i++)
            vect1[i] = vect1[i-1]*nums[i-1];

        for(int i=vect2.size()-2;i>=0;i--)
            vect2[i] = vect2[i+1]*nums[i+1];

        vector<int> ans;
        for(int i=0;i<nums.size();i++)
            ans.push_back(vect1[i]*vect2[i]);

        return ans;
    }
};
