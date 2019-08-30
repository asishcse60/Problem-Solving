/*
Time: O(M+N) or log(M) + O(n)
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]*/
public class Solution {
    public bool SearchMatrix(int[,] matrix, int target) {
        int numOfrow = matrix.GetLength(0);
        int numOfcol = matrix.GetLength(1);
        int row = 0; int col = numOfcol - 1;
        while(row < numOfrow && col>=0){
          if(matrix[row,col] == target) return true;
          else if(matrix[row,col]> target) col--;
          else row++;
        }
        return false;
    }
}