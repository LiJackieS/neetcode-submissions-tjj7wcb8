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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const auto& a, const auto& b) {
            return a.start == b.start ? a.end < b.end : a.start < b.start;
        });
        int prev_end = -1;
        for (const auto& interval : intervals) {
            int cur_start = interval.start; 
            if (cur_start < prev_end) {
                return false;
            }
            prev_end = interval.end;
        }
        return true;
    }
};
