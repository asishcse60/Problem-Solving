/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 1) return 1; 
        if(A[0] == 0) return 0;
        int cur = 0;
        for(int i = 0; i<n; i++)
         {
              if(A[i] == 0) {if(cur<i+1) return 0; else continue;}
              if(i+A[i]>cur){
                  cur = i+A[i];
                  if(cur>=n-1) return 1;
              }
             
         }
         return 0;
        
    }
};