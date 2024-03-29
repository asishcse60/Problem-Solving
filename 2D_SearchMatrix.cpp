/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int M = matrix.size(), row = 0;
        int N = matrix[0].size(), col = N-1;
        while(col>=0 && row<M){
            
            if(matrix[row][col] == target)  return true;
            else if(matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};