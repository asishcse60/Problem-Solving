/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = matrix.size();
        for(int lyr = 0; lyr<sz/2; lyr++){
            
                 int fst = lyr;
                 int lst = sz-1-lyr;
                 for(int i = fst;i<lst; i++){
                     int off = i-fst;
                     int top = matrix[fst][i];
                     matrix[fst][i] = matrix[lst-off][fst];
                     matrix[lst-off][fst] = matrix[lst][lst-off];
                     matrix[lst][lst-off] = matrix[i][lst];
                     matrix[i][lst] = top;
                 }
        }
        
    }
};