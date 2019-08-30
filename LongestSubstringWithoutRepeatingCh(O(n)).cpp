/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz=s.size() , cLen = 1, pInd, track[256], i,mx=0;
        if(sz==0) return 0;
        memset(track, -1, sizeof track);
        track[s[0]] = 0;
        for(i = 1;i<sz; i++)
        {
           pInd = track[s[i]];
           if(pInd == -1 || i-cLen>pInd) cLen++;
           else{
               mx = max(mx,cLen);
               cLen = i - pInd;
           }
           track[s[i]] = i;
        }
        mx = max(mx,cLen);
        return mx;
    }
};
