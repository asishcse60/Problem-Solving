Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
public class Solution {
    bool[,]dp;
    public bool Exist(char[,] board, string word) {
        
        int row = board.GetLength(0);
        int col= board.GetLength(1);
        dp = new bool[row,col];
        for(int i= 0; i<row; i++)
        for(int j = 0; j<col; j++)
            dp[i, j] = false;
        for(int i = 0; i<row; i++)
        for(int j = 0; j<col; j++)
        {
        
            bool res = IsWordFind(board, i , j, row, col, 0, word);
            if(res) return true;
        
        }
        return false;
    }
    
    public bool IsWordFind(char[,] board, int i, int j, int row, int col, int index, string word){
        
        if(index == word.Length) return true;
        if(i<0 || j<0 || i> row-1 || j>col-1) return false;
        if(board[i , j]!=word[index]) return false;
        if(dp[i, j]) return false;
        dp[i , j] = true;
        bool res = IsWordFind(board, i+1, j, row, col, index+1, word)||IsWordFind(board, i-1, j, row, col, index+1, word)||IsWordFind(board, i, j+1, row, col, index+1, word)||IsWordFind(board, i, j-1, row, col, index+1, word);
        dp[i, j] = false;
        return res;
    }
}