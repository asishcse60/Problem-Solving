/*Time: O(M*N)
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
public class Solution {
    long [,] dp;
    public int MinPathSum(int[,] grid) {
        int row = grid.GetLength(0);
        int col = grid.GetLength(1);
        dp = new long[row , col];
        for(int i = 0;i<row; i++)
          for(int j = 0; j<col; j++)
              dp[i , j] = (long)int.MaxValue;
        return (int)GetMinSum(grid, 0, 0, row, col);      
    }
    
    public long GetMinSum(int [,]grid , int curRow, int curCol, int endRow, int endCol){
    if(curRow == endRow-1 && curCol == endCol - 1) return grid[curRow, curCol];
    if(curRow >= endRow || curCol>= endCol) return (long)int.MaxValue;
   
    if(dp[curRow , curCol]!=(long)int.MaxValue) return dp[curRow , curCol];
    
    long downSum = GetMinSum(grid , curRow + 1, curCol, endRow, endCol)+grid[curRow , curCol];
    long rightSum = GetMinSum(grid , curRow, curCol +1, endRow, endCol)+grid[curRow , curCol];
    dp[curRow , curCol] = Math.Min(downSum , rightSum);
    return dp[curRow , curCol];
  }
}