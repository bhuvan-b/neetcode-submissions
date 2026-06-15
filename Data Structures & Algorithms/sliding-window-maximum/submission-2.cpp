class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0, r=0;
        vector<int> ans;
        map<int, int> mp;
        deque<int> q;

        while(l<=r && r<nums.size())
        {
            if(!q.empty())
            {
                while(!q.empty() && q.front()<nums[r])
                    q.pop_front();
            }
            while(!q.empty() && q.back()<nums[r])
            {
                q.pop_back();
            }
            q.push_back(nums[r]);

            if(r-l+1==k)
            {
                ans.push_back(q.front());
                if(nums[l]==q.front())
                    q.pop_front();
                l++;
            }
            r++;
        }

        return ans;
    }
};
