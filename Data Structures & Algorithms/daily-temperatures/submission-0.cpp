class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> ans(temperatures.size());

        for(int i=0;i<temperatures.size();i++)
        {
            while(!st.empty() && st.top().first<temperatures[i])
            {
                ans[st.top().second] = i - st.top().second;
                st.pop(); 
            }
            st.push({temperatures[i], i});
        }

        ans[st.top().second] = 0;

        return ans;
    }
};
