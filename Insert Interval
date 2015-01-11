/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        bool insert=true;
        for(int i=0; i<intervals.size(); ++i){
            if(intervals[i].end<newInterval.start)
                res.push_back(intervals[i]);
            else if(intervals[i].start>newInterval.end){
                if(insert){
                    res.push_back(newInterval);
                    insert=false;
                }
                res.push_back(intervals[i]);
            }else{
                if(intervals[i].start<newInterval.start)    newInterval.start=intervals[i].start;
                if(intervals[i].end>newInterval.end)    newInterval.end=intervals[i].end;
            }
        }
        if(insert)  res.push_back(newInterval);
        return res;
    }
};
