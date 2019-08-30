/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
public class Solution {
    public bool CanJump(int[] nums) {
        if(nums.Length == 0 || nums.Length == 1) return true;
        int lIndex = 0;
        for(int i = 0; i<nums.Length; i++){
         if(nums[i] == 0){
             
             if(lIndex < i + 1) return false;
             continue;
             
         }
         if(i + nums[i] > lIndex){
             lIndex = i + nums[i];
             if(lIndex >= nums.Length-1)
             return true;
         }

        }

        return false;
    }
}