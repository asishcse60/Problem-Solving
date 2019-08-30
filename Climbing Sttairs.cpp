/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
class Solution {
public:
    int dp[1005];
    int cc(int idx, int n) {
        if(idx == n) return 1;
        if(idx>n) return 0;
        int &ret = dp[idx];
        if(ret!=-1) return ret;
        ret = 0;
        int sum = 0;
        ret+=cc(idx+1,n)+cc(idx+2,n);
        return ret;
    }
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        memset(dp,-1,sizeof(dp));
        return cc(0,n);
        
    }
};