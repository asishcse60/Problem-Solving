/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
class Solution {
public:
int RotationIbinarySearch(int a[], int low, int up, int findNum){
   while(low<=up){
      int mid = (low+up)/2;
      if(a[mid] == findNum) return mid;
      else if(a[low]<=a[mid]){
        if(findNum>a[mid]) low = mid + 1;
        else if(findNum>=a[low]) up = mid-1;
        else low = mid + 1;
        if(a[mid-1] == findNum) return mid;
        
      }
     else if(a[mid]>findNum) {up = mid-1;}
     else if(a[up]>=findNum) {low = mid + 1;}
     else up = mid - 1;
   }
   return -1;
}
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int z = RotationIbinarySearch(A,0,n-1, target);
        return (z==-1)?0:1;
    }
};
//Another solution correct
class Solution {
public:

    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int mid, min = 0, max = n-1;

    while (min <= max) {
        while (min != max && A[min] == A[max]) {
            max--;
        }

        mid = (min + max) / 2;

        if (A[mid] == target) {
            return true;
        }

        if (A[mid] >= A[min]) {
            if (target > A[mid]) {
                min = mid + 1;
            } else {
                if (target >= A[min]) {
                    max = mid - 1;
                } else {
                    min = mid + 1;
                }
            }
        } else {
            if (target < A[mid]) {
                max = mid - 1;
            } else {
                if (target >= A[min]) {
                    max = mid - 1;
                } else {
                    min = mid + 1;
                }
            }
        }
    }

    return false;
    }
};