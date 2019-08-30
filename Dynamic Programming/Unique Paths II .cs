/*O(M*N)
Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
*/
public class Solution {
    int [,]dp;
    public int UniquePathsWithObstacles(int[,] obstacleGrid) {
        int m = obstacleGrid.GetLength(0);
        int n = obstacleGrid.GetLength(1);
        dp = new int[m,n];
        for(int i = 0; i<m; i++)
         for(int j = 0; j<n; j++){
           dp[i,j] = -1;
         }
         return GetTotalPath(0 , 0, m, n, obstacleGrid);
    }
    
    public int GetTotalPath(int curRow, int curCol, int endRow, int endCol, int[,] obstacleGrid){
       if(curRow == endRow - 1 && curCol == endCol - 1) {
           if(obstacleGrid[curRow , curCol]!=1)
              return 1;
              return 0;
       }
       if(curRow >=endRow ||curCol >= endCol) return 0;
       if(dp[curRow, curCol]!=-1)  return dp[curRow, curCol];
       dp[curRow, curCol]=0;
       if(obstacleGrid[curRow , curCol]!=1)
       dp[curRow, curCol] +=  GetTotalPath(curRow + 1, curCol, endRow, endCol, obstacleGrid); 
       if(obstacleGrid[curRow , curCol]!=1)
        dp[curRow, curCol] += GetTotalPath(curRow, curCol + 1, endRow, endCol, obstacleGrid);
       return dp[curRow, curCol]; 
    }
}