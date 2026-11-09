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
         if(intervals.empty())
            return true;
         sort(intervals.begin(),intervals.end(),[](const Interval& a, const Interval& b) {return a.start < b.start;});

         int lastend=intervals[0].end;
         for(int i=1;i<intervals.size();i++){
            int currentstart=intervals[i].start;
            int currentend=intervals[i].end;
            if(currentstart<lastend){
                return false;
            }
            lastend=currentend;
         }
    return true;
    }
};
