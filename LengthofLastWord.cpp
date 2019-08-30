/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = strlen(s)-1, t = 0, b = 0;
        for(int i = sz; i>=0; i--){
            
            if(s[i]!=' ') t++;
            else if(t) return t;
        }
        return t;
    }
};