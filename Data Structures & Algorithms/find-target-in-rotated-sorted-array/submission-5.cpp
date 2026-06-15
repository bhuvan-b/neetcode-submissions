class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;

        while(l<=r)
        {
            int m = l+(r-l)/2;
            if(nums[m]==target)
                return m;

            if(nums[l]<=nums[m])
            {
                if(target>=nums[l] && target<=nums[m])
                    r=m-1;
                else
                    l=m+1;
            }
            else if(nums[m]<=nums[r])
            {
                if(target>=nums[m] && target<=nums[r])
                    l=m+1;
                else
                    r=m-1;
            }

        }
        
        return -1;
    }
};

// nums=[3,4,5,6,1,2]
// target=1

// nums=[3,5,6,0,1,2]
// target=4

// nums=[4,5,6,7,0,1,2]
// target=0

// nums=[5,1,3]
// target=5
