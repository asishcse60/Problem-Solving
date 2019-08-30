/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int>ans; ans.clear(); 
        if(matrix.size() == 0) return ans;
        int startX = 0, endX = matrix[0].size()-1;
        int startY = 0, endY = matrix.size()-1;
        
        while(true){
            
            //left to right print
            for(int i = startX; i<=endX; i++) ans.push_back(matrix[startY][i]);
            if(++startY>endY) break;
            //top to bottom print
            for(int i = startY; i<=endY; i++) ans.push_back(matrix[i][endX]);
            if(startX>--endX) break;
            //right to left
            for(int i = endX;i>=startX;i--) ans.push_back(matrix[endY][i]);
            if(startY>--endY) break;
            //bottom to top
            for(int i = endY; i>=startY; i--) ans.push_back(matrix[i][startX]);
            if(++startX>endX) break;
            
        }
        return ans;
    }
};