/**
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
complexity: O(nlogn)
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
    public IList<Interval> Merge(IList<Interval> intervals) {
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