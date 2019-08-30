/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
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
    static bool com(Interval a, Interval b){
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval> &in) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval>ans;
        if(in.size()==0) return ans;
        std::sort(in.begin(),in.end(),Solution::com);
        ans.push_back(in[0]);
        for(int i=1;i<in.size();i++){
            if(ans.back().end >= in[i].start){
                ans.back().end = max(ans.back().end, in[i].end);
            }
            else ans.push_back(in[i]);
        }
        return ans;
    }
};