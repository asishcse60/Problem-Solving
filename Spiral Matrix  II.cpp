/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >ans(n,vector<int>(n));
        if(n==0) return ans;
        int startX = 0, endX =  n-1;
        int startY = 0, endY = n-1, cnt = 1;
        while(1){
            
            //left to right scan
            for(int i = startX; i<=endX; i++) ans[startY][i] = cnt++;
            if(++startY > endY) break;
            // top to bottom
            for(int i = startY; i<=endY; i++) ans[i][endX]=cnt++;
            if(startX > --endX) break;
            // right to left
            for(int i = endX; i>=startX; i--) ans[endY][i] = cnt++;
            if(startY>--endY) break;
            //bottom to top
            for(int i = endY; i>=startY; i--) ans[i][startX] = cnt++;
            if(++startX>endX) break;
        }
        return ans;
    }
};