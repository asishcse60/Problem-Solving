/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/
class Solution {
public:
    int cnt = 0;
    bool rowValid(int rr, int cc, int row[]){
        for(int c=0;c<cc; c++)
          if(abs(row[c]-rr)==abs(c-cc) || row[c] == rr) return 0;
          return 1;
    }
    int solve(int col, int n, int row[]){
        for(int i = 0; i<n; i++){
            if(rowValid(i,col,row)){
                row[col] = i;
                if(col == (n-1)) cnt++;
                else solve(col+1,n,row);
            }
            
        }
        return cnt;
    }
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        cnt=0;
        if(n == 0) return 0;
        int row[20];
        return solve(0,n,row);
    }
};