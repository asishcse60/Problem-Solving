Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

class Solution {
public:
    int dp[1005][1005];
    int CalculateSum(vector<vector<int>>& triangle, int row, int curRow, int curCol){
        if(curRow == (row-1)) return triangle[curRow][curCol];
        if(dp[curRow][curCol]!=INT_MAX) return dp[curRow][curCol];
        if((curRow + 1)< row)
        dp[curRow][curCol]= min(dp[curRow][curCol],CalculateSum(triangle , row, curRow +1, curCol)+triangle[curRow][curCol]);
        if((curRow+1)<row &&  (curCol+1)<triangle[curRow+1].size())
        dp[curRow][curCol] = min(dp[curRow][curCol],CalculateSum(triangle , row, curRow+1, curCol+1)+triangle[curRow][curCol]);
        return dp[curRow][curCol];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        if(triangle.size() == 0) return 0;
        int row = triangle.size();
        int col = triangle[0].size();
        for(int i = 0; i<row; i++)
            for(int j = 0; j<triangle[i].size(); j++)
                dp[i][j] = INT_MAX;
        return CalculateSum(triangle , row, 0, 0);
    }
};