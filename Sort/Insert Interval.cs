/*Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
*/
/**
 * Definition for an interval.
 * public class Interval {
 *     public int start;
 *     public int end;
 *     public Interval() { start = 0; end = 0; }
 *     public Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    List<Interval>MergeInterval = new List<Interval>();
    public IList<Interval> Insert(IList<Interval> intervalsOrigin, Interval newInterval) {
        if(intervalsOrigin.Count == 0 && newInterval!=null){MergeInterval.Add(newInterval); return MergeInterval;}
        List<Interval>intervals = new List<Interval>(intervalsOrigin);
        if(newInterval!=null) intervals.Add(newInterval);
        if(intervals.Count == 0) return MergeInterval;
        List<Interval> interval = new List<Interval>();
        interval = new List<Interval>(intervals.OrderBy(o => o.start));
        int startIndex = 0; 
        int endIndex = 0;
        Interval iVal;
        for(int i = 1; i<intervals.Count; i++){
           if(interval[endIndex].end >= interval[i].start && interval[endIndex].end<=interval[i].end){
               endIndex = i;
           }
           else if(interval[endIndex].end >= interval[i].start && interval[endIndex].end > interval[i].end){
               continue;
           }
           else{
               iVal = new Interval();
               iVal.start = Math.Min(interval[startIndex].start, interval[endIndex].start);
               iVal.end = Math.Max(interval[endIndex].end, interval[startIndex].end);
               MergeInterval.Add(iVal);
               startIndex = i;
               endIndex = i;
           }
        }
         iVal = new Interval();
         iVal.start = Math.Min(interval[startIndex].start, interval[endIndex].start);
         iVal.end = Math.Max(interval[endIndex].end, interval[startIndex].end);
         MergeInterval.Add(iVal);
         return MergeInterval;
    }
}