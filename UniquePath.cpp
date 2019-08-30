/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/
class Solution {
public:
    int dp[101][101]; 
    int Call(int x, int y, int m, int n){
        
        if(x == (m-1) && y == (n-1)) return 1; 
        if(x>=m || y>=n) return 0;
        int &ret = dp[x][y];
        if(ret!=-1) return ret;
        ret = 0;
        ret+=Call(x+1,y,m,n) + Call(x,y+1,m,n);
        return ret;
    }
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m==0 && n ==0) return 0;
        memset(dp,-1,sizeof dp);
        return Call(0,0,m,n);
    }
};