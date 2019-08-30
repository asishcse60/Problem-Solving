/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
class Solution {
public:
    int inf=9999999;
    bool isPalin(int lw, int up,string s,vector<vector<int>>&P){
        if(lw>=up) return 1;
        int &ret = P[lw][up];
        if(ret!=-1) return 1;
        if(s[lw]!=s[up]) return 0;
        else ret = isPalin(lw+1,up-1,s,P);
        return ret;
    }
    int rec(int cur, int len,  vector<vector<int>>&dp,vector<vector<int>>&P){
        if(cur>len) return 0;
        if(P[cur][len]) return 1;
        int &ret = dp[cur][len];
        if(ret!=-1) return ret;
        ret = inf;
        for(int i = cur; i<len; i++){
            if(P[cur][i])
               ret = min(ret, 1+ rec(i+1,len,dp,P));
        }
        return ret;
    }
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       // memset(dp,-1,sizeof dp);
      //  memset(P, -1, sizeof P);
        int sz = s.size();
        if(sz==0) return 0;
        vector<vector<int>>dp(sz,vector<int>(sz,-1));
        //vector<int>dp(sz,-1);
        
        vector<vector<int>>P(sz,vector<int>(sz,-1));
        for(int i = 0; i<sz; i++)
         for(int j =i;j<sz; j++)
           if(P[i][j]== -1)
              P[i][j] = isPalin(i,j,s,P);
              
         return rec(0,sz-1,dp,P)-1;          
    }
};
-----------------------------------------------------------------------
//Another solution
class Solution {
public:
    int minCut(string str){

        int leng = str.size();

        int dp[leng+1];
        bool palin[leng][leng];

      for(int i = 0; i <= leng; i++)
        dp[i] = leng-i;
        for(int i = 0; i < leng; i++)
            for(int j = 0; j < leng; j++)
                palin[i][j] = false;

      for(int i = leng-1; i >= 0; i--){
        for(int j = i; j < leng; j++){
          if(str[i] == str[j] && (j-i<2 || palin[i+1][j-1])){
            palin[i][j] = true;
            dp[i] = min(dp[i],dp[j+1]+1);
          }
        }
      }
      return dp[0]-1;
    }
};