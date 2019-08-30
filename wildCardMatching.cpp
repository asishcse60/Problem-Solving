/*
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
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char* st = NULL;
        const char* ss=s; 
        while(*s){
            if((*s==*p) || *p=='?'){s++;p++;}
            else if(*p=='*'){st=p;p++;ss=s;}
            else if(st){p=st+1;s=++ss;}
            else return 0;
        }
        while(*p=='*') p++;
        return !*p;
    }
};