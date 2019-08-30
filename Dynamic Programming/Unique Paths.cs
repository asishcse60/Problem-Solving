/*Time:O(M*N)
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/
public class Solution {
    int [,]dp;
    public int UniquePaths(int m, int n) {
        dp = new int[m,n];
        for(int i = 0; i<m; i++)
         for(int j = 0; j<n; j++){
           dp[i,j] = 0;
         }
         return GetTotalPath(0 , 0, m, n);
    }
    
    public int GetTotalPath(int curRow, int curCol, int endRow, int endCol){
       if(curRow == endRow - 1 && curCol == endCol - 1) return 1;
       if(curRow >=endRow ||curCol >= endCol) return 0;
       if(dp[curRow, curCol]!=0)  return dp[curRow, curCol];
       dp[curRow, curCol] +=  GetTotalPath(curRow + 1, curCol, endRow, endCol) + GetTotalPath(curRow, curCol + 1, endRow, endCol);
       return dp[curRow, curCol]; 
    }
}