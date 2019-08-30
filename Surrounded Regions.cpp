/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region .

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
class Solution {
        const int X[4] = {0,0,1,-1};
        const int Y[4] = {1,-1,0,0};
public:
    vector<pair<int,int> >vs;
    void solve(vector<vector<char>> &b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int R = b.size();
        if(R<=2) return;
        int C = b[0].size();
        for(int i = 0; i<R; i++)
            for(int j = 0; j<C; j++){
                if((i==0 || j==0 || i==(R-1) || j==(C-1)) && b[i][j]=='O'){
                    b[i][j] = 'B';
                    vs.push_back(make_pair(i,j));
                }
            }
    
            while(!vs.empty()){
                 int ii = vs.back().first;
                 int jj = vs.back().second;
                 vs.pop_back();
                 for(int i = 0;i<4; i++){
                     int x = X[i] + ii;
                     int y = Y[i] + jj;
                     if(x>=0 && y>=0 && x<R && y<C){
                         if(b[x][y]=='O'){
                         b[x][y] = 'B';
                          vs.push_back(make_pair(x,y));
                         }
                     }
                 }
            }
            for(int i = 0; i<R; i++)
             for(int j = 0; j<C; j++){
                 if(b[i][j]!='X'){
                     b[i][j] = (b[i][j]=='O'?'X':'O');
                 }
             }

    }
};