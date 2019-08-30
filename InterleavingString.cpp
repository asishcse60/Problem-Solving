/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        int a = s1.size(), b= s2.size(), c= s3.size(), i,j;
        bool tak[b+1];
        if(a+b != c) return 0;
        memset(tak,0,sizeof tak);
        tak[b] = 1;
        for (j=b-1; j>=0; j--)
        if (!(tak[j] = s3[a+j] == s2[j] && tak[j+1]))
            break;
      
        for(i = a-1;i>=0;i--)
        {
           for(j = b - 1; j>=0; j--)
            if(s3[i+j] == s1[i] && tak[j]) tak[j] = 1;
            else if(s3[i+j] == s2[j] && tak[j+1]) tak[j]=1;
            else tak[j] = 0;
           tak[b] = s3[b+i]==s1[i]&&tak[b];
        }  
        return tak[0];
    }
};