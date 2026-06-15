class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans=0;

        vector<int> fe;
        for(auto& it: st)
        {
            if(st.count(it-1))
                continue;
            else
                fe.push_back(it);
        }

        for(auto& it: fe)
        {
            int count=0, val=it;
            while(st.count(it))
            {
                count++;
                it++;
            }
            ans=max(ans, count);
        }
        
        return ans;
    }
};
