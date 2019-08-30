/*Time: worstCase O(n) avg: log(n)
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

public class Solution {
     public bool Search(int[] nums, int target) {
        int low = 0; int high=nums.Length-1;
       
        
        while(low <= high){
        
           int mid = (low + high)/2;
           if(nums[mid] == target) return true;
           else if( (nums[low] == nums[mid]) && (nums[high] == nums[mid]) ) {++low; --high;}
           else if(nums[low]<=nums[mid]){
               if(target >nums[mid]) low = mid + 1;
               else if(target>=nums[low]) high = mid - 1;
               else low = mid +1;
             
           }
           else if(nums[mid]>target) high = mid - 1;
           else if(nums[high]>= target) low = mid + 1;
           else high = mid-1;
          
        }
        return false;
    }
}