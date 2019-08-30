/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cnt = 1,i,j,k=0,sum=0;
        if(n<=2) return n;
        for(i= 1;i<n;i++){
          if(A[i]!=A[k]){
              A[++k] = A[i];
              cnt=1;
          }
          else{
              if(cnt<2){
                  A[++k] = A[i];
                  cnt++;
              }
          }
        }
        
        return k+1;
    }
};