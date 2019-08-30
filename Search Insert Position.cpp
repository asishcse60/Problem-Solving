/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
#include<iostream>
using namespace std;

int BS(int A[], int n, int target){

          int lo = 0, hi = n-1, mid = (lo+hi)/2;
          while(lo<=hi && A[mid]!=target){
               if(A[mid]>target) hi= mid-1;
               else lo = mid + 1;
               mid = (lo+hi)/2;
          }
         // cout<<lo<<" "<<hi<<" "<<mid<<endl;
          if(A[mid] == target) return mid;
          return lo;
    }
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return BS(A,n,target);
    }
    int main(){

       int A[1005], n, i;
       while(cin>>n){
           for(i=0;i<n;i++) cin>>A[i];
           cout<<searchInsert(A,n,5)<<endl;
       }
       return 0;
    }
