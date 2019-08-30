/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
class Solution {
public:
    int maxProfit(vector<int> &p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = p.size();
        if(sz<=1) return 0;
        int mx=0,sum=0;
        for(int i = 1; i<sz; i++){
            if(p[i]>p[i-1]){
                sum+=p[i] - p[i-1];
            }
            else{
                mx+=sum; sum=0;
            }
        }
        mx+=sum;
        return mx;
    }
};