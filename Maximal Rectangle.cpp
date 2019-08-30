//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size(),ans=0;
        if(row == 0) return 0;
        int col = matrix[0].size();
        vector<int>hori(col,0);
        vector<int>L(col);
        vector<int>R(col,col);
        for(int i = 0; i<row; i++){
            
            int left=0, right = col;
             for(int j = 0;j<col; j++){  //left to right scan
                 if(matrix[i][j] == '1'){
                     hori[j]++;
                     L[j] = max(L[j],left);
                 }
                 else{
                     left=j+1;
                     hori[j] =0; L[j] =0; R[j] =col;
                 }
             }
             
             for(int j = col-1;j>=0;j--){
                 
                 if(matrix[i][j] == '1'){
                     
                     R[j] = min(right,R[j]);
                     ans = max(ans, hori[j]*(R[j]-L[j]));
                 }
                 else right = j;
             }
        }
        
        return ans;
    }
};