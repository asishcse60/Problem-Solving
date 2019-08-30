/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
public class Solution {
    public int Search(int[] nums, int target) {
        int low = 0; int high=nums.Length - 1;
       
        
        while(low <= high){
        
           int mid = (low + high)/2;
           if(nums[mid] == target) return mid;
           else if(nums[low]<=nums[mid]){
               if(target >nums[mid]) low = mid + 1;
               else if(target>=nums[low]) high = mid - 1;
               else low = mid +1;
           
           }
           else if(nums[mid]>target) high = mid - 1;
           else if(nums[high]>= target) low = mid + 1;
           else high = mid -1;
        
        }
        return -1;
    }
}