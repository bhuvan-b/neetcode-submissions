class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        deque<vector<int>> q;
        vector<vector<int>> ans;

        if(intervals.size()==0)
        {
            ans.push_back(newInterval);
            return ans;
        }

        int i=0;
        bool pushed = false;
        while(i<intervals.size())
        {
            if(!pushed && newInterval[0]<intervals[i][0])
            {
                q.push_back(newInterval);
                pushed = true;
                break;
            }
            q.push_back(intervals[i]);
            i++;
        }

        while(i<intervals.size())
        {
            q.push_back(intervals[i]);
            i++;
        }

        if(!pushed)
            q.push_back(newInterval);

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

// [3, 5]

// [2, 4] [7, 9] [13, 15]

// [2, 4] [3, 5] [7, 9] [13, 15]

// [2, 6] [3, 5] [7, 9] [13, 15]

// [2, 5] [6, 9] [13, 15]