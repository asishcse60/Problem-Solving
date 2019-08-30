/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = 0, high = n, mid;
        vector<int>a(2, -1);
        //lower find
        while(low<high)
        {
            mid = (low + high)/2;
            if(A[mid] < target) low = mid + 1;
            else high = mid;
        }
        if(A[low]!=target) return a;
        a[0] = low;
        //upper found
        high = n;
         while(low<high)
        {
            mid = (low + high)/2;
            if(A[mid] > target) high = mid;
            else low = mid+1;
        }a[1] = high - 1;
        return a;
        
    }
};