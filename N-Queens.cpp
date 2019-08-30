/*
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
*/
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define minusINF -(1<<30)
#define ll long long
#define sz 1005
using namespace std;

bool rowValid(int rr, int cc, int row[]){
    //cout<<cc<<endl;
    for(int c=0;c<cc;c++){
        if(abs(row[c]-rr) == abs(c-cc) || row[c] == rr) return 0; //diagonal or row,col check
    }
    return 1;
}

void solve(int col, int n, int row[], vector<vector<string> >&Q){
     for(int i = 0; i<n; i++){
        if(rowValid(i,col,row)){
                row[col] = i;
                if(col==(n-1))
                {    //cout<<i<<endl;
                      vector<string>str;
                      string s="";
                      for(int j = 0;j<n;j++) s.push_back('.');
                      for(int j = 0;j<n;j++)
                          str.push_back(s);
                      for(int k= 0;k<n; k++)
                          str[k][row[k]]='Q';
                     // cout<<"a"<<endl;
                   Q.push_back(str);
                  // cout<<Q.size()<<endl;
                }
               else
                 solve(col + 1, n, row, Q);
        }
     }
}
vector<vector<string> > solveNQueens(int n){
    vector<vector<string> >Q;
    Q.clear();
    int row[20];
    solve(0, n, row , Q);
   // cout<<Q.size()<<endl;
    return Q;
}

int main(){
     int n;
     while(cin>>n){
          solveNQueens(n);
     }
   return 0;
}
