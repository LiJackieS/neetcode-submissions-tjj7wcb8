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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,int>> time;
        int res = 0;
        for (const auto& interval : intervals) {
            time.push_back({interval.start, 1});
            time.push_back({interval.end, -1});
        }

        sort(time.begin(), time.end(), [](auto& a, auto& b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });
        int cur = 0;
        for (const auto& n : time) {
            cur += n.second;
            res = max(cur, res);
        }
        return res;
    }
};
