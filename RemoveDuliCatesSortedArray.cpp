/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0, j;
        if(n==0) return 0;
        if(n==1) return 1;
        for(j=0;j<n-1;j++){
            
            if(A[j]!=A[j+1])
               A[i++] = A[j];
        }
        A[i++] = A[n-1];
        return i;
    }
};