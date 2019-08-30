/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
class Solution {
public:
   void gP(int left, int right, int n , vector<string>&ans, string S){
       if(left == n){
           ans.push_back(S.append(n-right,')'));
           return;
       }
       gP(left+1,right,n,ans,S+"(");
       if(left>right)
            gP(left, right+1, n,ans,S+")");
       return;
   }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string>ans;
        if(n>0) gP(0,0,n,ans,"");
        return ans;        
    }
};