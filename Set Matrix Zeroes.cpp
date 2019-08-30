/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
--> constand memory
*/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size(), r1=0;
        int col = matrix[0].size(), c1=0;
        if(!row || !col) return;
        for(int i = 0; i<row; i++)
          if(matrix[i][0] == 0){r1=1; break;}
        for(int j = 0; j<col; j++)
          if(matrix[0][j] == 0){c1=1; break;}
        for(int i = 1; i<row; i++)
         for(int j = 1; j<col; j++)
           if(matrix[i][j] == 0){
               matrix[i][0] = 0;
               matrix[0][j] = 0;
           }
        for(int i = 1; i<row; i++){
            if(matrix[i][0]==0){
                for(int j = 0; j<col; j++)
                  matrix[i][j] = 0;
            }
        }
        
         for(int i = 1; i<col; i++){
            if(matrix[0][i]==0){
                for(int j = 0; j<row; j++)
                  matrix[j][i] = 0;
            }
        }
        if(r1)
        for(int i = 0; i<row; i++)
            matrix[i][0] = 0;
        if(c1)
        for(int j = 0; j<col; j++)
           matrix[0][j] = 0;
        return;
    }
};