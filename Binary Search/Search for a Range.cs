/*Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].*/
public class Solution {
    public int[] SearchRange(int[] nums, int target) {
        int [] num =new int[2]{-1, -1};
        int ind = BinarySearch(0 , nums.Length, nums, target, 1);
        if(ind == -1) return num;
        num[0] = ind;
        ind = BinarySearch(ind , nums.Length, nums, target, 2);
        num[1] = ind;
        return num;
    }
    
    public int BinarySearch(int low, int high, int[] nums, int target, int track){
     int minLow =  int.MaxValue;  
     int maxHigh = int.MinValue;
       while(low < high){
          int mid = (low + high)/2;
          if(nums[mid] == target){
              if(track ==1){
                 minLow = Math.Min(minLow , mid);
                 high = mid;
                 if(nums[low] == target) return low;
              }
              else{
                  maxHigh = Math.Max(maxHigh , mid);
                  low = mid + 1;
              }
              
          }
          else if(nums[mid] > target) high = mid;
          else low = mid +1;
       }
       if(track ==1){
       if(minLow == int.MaxValue) return -1;
       return minLow;
       }
       if(maxHigh == int.MinValue) return low;
       return maxHigh;
    }
}