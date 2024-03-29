/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
public class Solution {
    public int FindMin(int[] nums) {
        
        int low  = 0; int high = nums.Length - 1;
        
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[high])
                low = mid + 1;
            else high = mid;
        }
     
        return nums[low];
    }
}