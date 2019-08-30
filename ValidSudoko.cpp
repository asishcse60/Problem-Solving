/*
	Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool row[100][100], col[100][100], blk[100][100];
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(blk, 0, sizeof blk);
        for(int i = 0; i<board.size();i++)
         for(int j =0;j<board[i].size();j++){
             
             if(board[i][j] == '.') continue;
             int num = board[i][j]-'1';
             if(row[i][num]||col[j][num] || blk[i-i%3-j/3][num]) return false;
             row[i][num] = col[j][num] = blk[i-i%3-j/3][num] = true;
         }
        return true;
    }
};