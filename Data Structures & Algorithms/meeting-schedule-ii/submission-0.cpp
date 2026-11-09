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
        sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval &b){return a.start<b.start;});
        priority_queue<int, vector<int>, greater<int>> minheap;
        int maxroom=0;
        for(const auto &interval:intervals){
            if(!minheap.empty() && interval.start >=minheap.top()){
                minheap.pop();
            }
            minheap.push(interval.end);
            maxroom = max(maxroom, (int)minheap.size());
        }
    return maxroom;
    }
};
