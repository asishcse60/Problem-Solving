/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true
*/
class Solution {
public
    bool isMatch(const char s, const char p) {
        // Start typing your CC++ solution below
         //DO NOT write int main() function
        if(*p==NULL) return *s==NULL;
        if(*(p+1)!='*'){
            return ((*s==*p)||(*p=='.' && *s != NULL)) && isMatch(s+1,p+1);
        }
        while((*s==*p)||(*p=='.' && *s!= NULL)){
            if(isMatch(s,p+2)) return 1;
            s++;
        }
        return isMatch(s,p+2);
    }
};
