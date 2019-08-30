/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
class Solution {
public:
    int maxProfit(vector<int> &p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = p.size();
        if(sz<=1) return 0;
        vector<int>tmp; int mx  =0;tmp.clear();
        tmp.push_back(0);
        int st = *p.begin(),ed;
        for(int i = 1;i<sz;i++){
            mx = max(mx,p[i]-st);
            st = min(st,p[i]);
            tmp.push_back(mx);
        }
        mx = 0; ed = *(p.end()-1);
        for(int i = p.size()-2; i>=0; i--){
            mx = max(mx,ed-p[i]+tmp[i]);
            ed = max(ed,p[i]);
        }
        return mx;
    }
};