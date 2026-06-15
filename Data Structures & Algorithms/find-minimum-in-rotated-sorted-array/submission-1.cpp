class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, r=nums.size()-1, ans=INT_MAX;

        while(l<=r)
        {
            int m = (l+r)/2;
            ans=min(ans, nums[m]);

            if(nums[l]>nums[m])
                r=m-1;
            else if(nums[r]<nums[m])
                l=m+1;
            else
                r=m-1;
        }

        return ans;
    }
};
