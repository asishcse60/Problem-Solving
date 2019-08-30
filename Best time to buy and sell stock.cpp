/*
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/
class Solution {
public:
    int maxProfit(vector<int> &p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = p.size(),mx=0,tmp;
        if(sz<=1) return 0;
        vector<int>mn;mn.clear();
        mn.push_back(p[0]); tmp = p[0];
        for(int i = 1;i<sz; i++){
            tmp=min(tmp,p[i]);
            mn.push_back(tmp);
        }
         for(int i = 1; i<sz; i++)
           mx = max(mx, p[i] - mn[i-1]);
         return mx;
    }
};