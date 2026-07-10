class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        deque<vector<int>> q;

        sort(intervals.begin(), intervals.end());

        for(int i=0;i<intervals.size();i++)
        {
            q.push_back(intervals[i]);
        }
        vector<vector<int>> ans;

        while(!q.empty())
        {
            vector<int> el = q.front();
            q.pop_front();

            if(q.empty())
            {
                ans.push_back(el);
                break;
            }

            vector<int> fr = q.front();

            if(el[1]<fr[0])
            {
                ans.push_back(el);
            }
            else
            {
                el[1] = max(el[1], fr[1]);
                q.pop_front();
                q.push_front(el);
            }
        }
        return ans;
    }
};
