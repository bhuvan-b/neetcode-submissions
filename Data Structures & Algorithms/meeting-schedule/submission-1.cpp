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
    static bool compareInt(Interval& a, Interval& b)
    {
        return a.start<b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        int minLeft=INT_MAX, maxRight=INT_MIN;
        sort(intervals.begin(), intervals.end(), compareInt);

        for(int i=0;i<intervals.size();i++)
        {
            if(!(intervals[i].start>=maxRight || intervals[i].end<=minLeft))
                return false;

            minLeft = min(minLeft, intervals[i].start);
            maxRight = max(maxRight, intervals[i].end);
        }

        return true;
    }
};



