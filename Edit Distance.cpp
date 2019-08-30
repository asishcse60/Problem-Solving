/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
class Solution {
public:
    
    int minDistance(string w1, string w2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = w1.size(), len2 = w2.size(),i,j,cost;
        int dp[len1+1][len2+1];
        if(len1==0) return len2;
        if(len2==0) return len1;
        if(len1==0 && len2==0) return 0; 
        
        for(i=0;i<=len1;i++) dp[i][0]=i;
        for(i=0;i<=len2;i++) dp[0][i]=i;
        
        for(i = 1;i<=len1; i++)
        for(j=1;j<=len2;j++){
            cost = (w1[i-1] == w2[j-1])?0:1;
            dp[i][j] = min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+cost));
            
        }
        return dp[len1][len2];
    }
};