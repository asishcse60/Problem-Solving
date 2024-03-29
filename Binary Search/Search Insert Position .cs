/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ? 2
[1,3,5,6], 2 ? 1
[1,3,5,6], 7 ? 4
[1,3,5,6], 0 ? 0
*/
public class Solution {
    public int SearchInsert(int[] nums, int target) {
        
        int low  = 0; int high =nums.Length - 1;
        int mid = (low + high)/2;
        while(low<=high && nums[mid] != target){
        if(nums[mid]> target)
           high = mid - 1;
         else
             low = mid + 1;
           mid = (low + high)/2;  
        } 
        if(nums[mid]== target) return mid;
        return low;
    }
}