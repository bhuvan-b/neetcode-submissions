class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> vect(nums.size() + 1);
        vector<int> ans;

        unordered_map<int, int> mp;

        for(int i=0;i<nums.size();i++)
        { 
            mp[nums[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            vect[it->second].push_back(it->first);
        }

        for(int i=vect.size() - 1;i>=0;i--)
        {
            if(vect[i].size()!=0)
            {
                for(int j=0;j<vect[i].size();j++)
                {
                    ans.push_back(vect[i][j]);
                    k--;
                    if(k==0)
                    {
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};