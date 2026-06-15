class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<vector<int>> track(nums.size(), vector<int> (2));

        for(int i=0;i<nums.size();i++)
        {
            track[i][0] = nums[i];
            track[i][1] = i;
        }

        sort(track.begin(), track.end());

        int i=0, j=nums.size()-1;

        while(i<j)
        {
            int sum = track[i][0]+track[j][0];
            if(sum==target)
            {
                if(track[i][1] < track[j][1])
                {
                    res.push_back(track[i][1]);
                    res.push_back(track[j][1]);
                }
                else{
                    res.push_back(track[j][1]);
                    res.push_back(track[i][1]);
                }
                return res;
            }
            else if(sum>target)
                j--;
            else
                i++;
        }

        return res;
    }
};
