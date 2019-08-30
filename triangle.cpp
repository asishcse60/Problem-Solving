/*
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
*/
//Large input
class Solution {
public:
    int minimumTotal(vector<vector<int> > &t) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = t.size(), i, j,k,kk;
        if(m == 0) return m;
        for(i = 1; i<m; i++){
            for(j = 0; j<t[i].size(); j++){
                if(j==0) t[i][j]+=t[i-1][j];
                else if(j>0){
                    if(j<i) t[i][j]+=min(t[i-1][j-1], t[i-1][j]);
                    else t[i][j]+= t[i-1][j-1];
                }
            }
        }
        int mn= 999999;
        for(i=0;i<m;i++)
         mn = min(mn,t[m-1][i]);
         return mn;
    }
};
//Small input
class Solution {
public:
int dp[501][501], inf = 99999;
    int Call(int curR, int curC, int row, vector<vector<int> > t){
       if(curR == row-1){
           return (curC<=curR)?t[curR][curC]:inf;
       }
       if(curC>=row) return inf;
       int &ret = dp[curR][curC];
       if(ret!=-1) return ret;
       ret = min((t[curR][curC] + Call(curR+1,curC,row,t)),(t[curR][curC] + Call(curR+1,curC+1,row,t)));
       return ret;
    } 
    int minimumTotal(vector<vector<int> > &t) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = t.size(), i, j,k,kk;
        memset(dp,-1,sizeof dp);
        return Call(0, 0, m, t);
    }
};