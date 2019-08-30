/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.
*/
class Solution {
public:
int dp[101][101]; 
    int Call(int x, int y, int m, int n,vector<vector<int> > obstacleGrid){
        
        if(x>=m || y>=n) return 0;
        if(x == (m-1) && y == (n-1)) {
            if(obstacleGrid[x][y]!=1) return 1;
            return 0;
        }
        int &ret = dp[x][y];
        if(ret!=-1) return ret;
        ret = 0;
        if((x+1)<m && obstacleGrid[x+1][y]!=1)
            ret+=Call(x+1,y,m,n,obstacleGrid);
        if((y+1)<n && obstacleGrid[x][y+1]!=1)
            ret+=Call(x,y+1,m,n,obstacleGrid);
        return ret;
    }
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m, n;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        if(m==0 && n ==0) return 0;
        memset(dp,-1,sizeof dp);
        if(obstacleGrid[0][0]!=1)
          return Call(0,0,m,n, obstacleGrid);
         return 0;
        
    }
};