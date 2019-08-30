/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = 0, i, j; string ss="";
        
        for(i = 0; s[i]; i++){
            char a = tolower(s[i]);
          if((a>='a' && a<='z') || (a>='0' && a<='9')) {ss.push_back(a);sz++;}
        }
          
          if(sz==0) return true;
          
          for(i = 0, j=sz-1; i<j;i++,j--)
           if(ss[i]!=ss[j]) return false;
       return true;
    }
};