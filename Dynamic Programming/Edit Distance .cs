/*Edit Distance: O(M*N)
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
public class Solution {
    public int MinDistance(string word1, string word2) {
        
        int len1 = word1.Length;
        int len2 = word2.Length;
        if(len1 == 0 && len2 == 0) return 0;
        if(len1 == 0) return len2;
        if(len2 == 0) return len1;
        int [,]dp = new int[len1+ 1, len2+1];
        for(int i = 0; i<=len1; i++) dp[i,0]=i;
        for(int i = 0; i<=len2; i++) dp[0,i]=i;
        
        for(int i = 1; i<=len1; i++)
        for(int j = 1; j<=len2; j++){
         int cost = (word1[i-1]==word2[j-1])?0:1;
         dp[i,j] = Math.Min(dp[i-1, j]+1, Math.Min(dp[i , j - 1]+1, dp[i-1, j-1]+cost));
        }
        return dp[len1 , len2];
    }
}