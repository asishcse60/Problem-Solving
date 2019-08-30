/*
	Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0,j;
        for(j = 0; j<n; j++)
          if(A[j]!=elem) A[i++] = A[j];
        return i;  
        
    }
};