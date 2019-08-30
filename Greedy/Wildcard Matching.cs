/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "*") ? true
isMatch("aa", "a*") ? true
isMatch("ab", "?*") ? true
isMatch("aab", "c*a*b") ? false
*/
public class Solution {
    public bool IsMatch(string s, string p) {
        if(p.Replace("*","").Length > s.Length) return false;
        var dp = new bool[s.Length + 1];
        dp[0] = true;
        for(int i = 1; i<s.Length; i++)
            dp[i] = false;
        for(int i = 1; i<=p.Length; i++){
            char pChar = p[i-1];
            if(pChar == '*'){
                for(int j = 1; j<=s.Length; j++)
                dp[j] = dp[j-1] || dp[j];
            }
            else{
                for(int j = s.Length; j>=1; j--)
                dp[j] = dp[j-1]&&(pChar=='?' || pChar == s[j-1]);
            }
           dp[0] = dp[0] && pChar=='*';
        }
        return dp[s.Length];
    }
}