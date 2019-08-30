/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==1) return A[0];
        int sum = 0, mx = 0,nmx = -99999999, cnt = 0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum>mx) mx = sum;
            else if(sum<0) { cnt++; sum =0; nmx=max(nmx,A[i]);}
        }
        if(cnt == n) return nmx;
        return max(sum,mx);
    }
};