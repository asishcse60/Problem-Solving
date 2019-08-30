/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int mxL= 0,i,j, wt =0, h =0;
        for(i=0;i<n;i++)
          if(A[i]>A[mxL]) mxL = i;
        for(i=0;i<mxL;i++)
         if(h>A[i]) wt+=h-A[i];
         else h=A[i];
        h=0;
        for(i=n-1;i>=mxL;i--)
          if(h>A[i]) wt+=h-A[i];
          else h = A[i];
        return wt;        
    }
};