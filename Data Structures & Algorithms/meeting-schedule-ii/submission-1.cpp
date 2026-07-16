/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool func(Interval& a, Interval& b)
    {
        return a.start<b.start;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> q;
        sort(intervals.begin(), intervals.end(), func);
        // int cnt=0;
        for(int i=0;i<intervals.size();i++)
        {
            if(q.empty())
            {
                q.push(intervals[i].end);
                continue;
            }

            if(intervals[i].start>=q.top())
                q.pop();

            q.push(intervals[i].end);
        }
        return q.size();
    }
};
