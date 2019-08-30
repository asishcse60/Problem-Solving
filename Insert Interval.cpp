/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*//**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 * place option: map is a solution 
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &in, Interval newI) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ans;
    int i = 0;
    int n = in.size();
    while(i < n && newI.start > in[i].end)
        ans.push_back(in[i++]);
    while(i < n && newI.end >= in[i].start) {
        newI.end = max(newI.end, in[i].end);
        newI.start = min(newI.start, in[i].start);
        ++i;
    }
    ans.push_back(newI);
    while(i < n)
        ans.push_back(in[i++]);
    return ans;
    }
};