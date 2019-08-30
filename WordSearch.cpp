/*
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
*/
class Solution {
public:
    bool Find(vector<vector<char> >&b, vector<vector<bool> >&visit, int i, int j, string word){
       if(word.size()==0) return 1;
        else{
        if((i-1>=0) && (b[i-1][j]==word[0]) && (visit[i-1][j]==0)){
            visit[i-1][j]=1;
            if(Find(b,visit,i-1,j,word.substr(1))) return 1;
            visit[i-1][j] = 0;
        }
        if((i+1<b.size()) &&( b[i+1][j]==word[0]) && (visit[i+1][j]==0)){
            visit[i+1][j]=1;
            if(Find(b,visit,i+1,j,word.substr(1))) return 1;
            visit[i+1][j] = 0;
        }
        if((j-1>=0) && (b[i][j-1]==word[0]) && (visit[i][j-1]==0)){
            visit[i][j-1]=1;
            if(Find(b,visit,i,j-1,word.substr(1))) return 1;
            visit[i][j-1] = 0;
        }
        if((j+1<b[0].size()) && (b[i][j+1]==word[0]) && (visit[i][j+1]==0)){
            visit[i][j+1]=1;
            if(Find(b,visit,i,j+1,word.substr(1))) return 1;
            visit[i][j+1] = 0;
        }
        }
        return 0;
    }
    bool exist(vector<vector<char> > &b, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = word.size();
        if(sz==0) return 0;
        for(int i = 0;i<b.size(); i++)
          for(int j=0;j<b[0].size();j++){
              if(word[0] == b[i][j])
              {
                  if(sz == 1) return 1;
                  else{
                      vector<vector<bool> > visit(b.size(),vector<bool>(b[0].size(),false));
                      visit[i][j]=1;
                      if(Find(b,visit, i, j,word.substr(1))) return 1;
                  }
              }
          }
        return 0;
    }
};