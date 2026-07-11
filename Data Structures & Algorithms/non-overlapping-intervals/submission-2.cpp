class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        deque<vector<int>> q;
        int cnt = 0;

        for(int i=0;i<intervals.size();i++)
        {
            q.push_back(intervals[i]);
        }

        while(!q.empty())
        {
            vector<int> el = q.front();
            q.pop_front();
            
            if(q.empty())
                break;

            vector<int> fr = q.front();

            if(fr[0]<el[1])
            {
                q.pop_front();
                cnt++;
                if(el[1]<fr[1])
                {
                    q.push_front(el);
                }
                else
                {
                    q.push_front(fr);
                }
            }
        }

        return cnt;
    }
};


// sort & remove the longer interval

