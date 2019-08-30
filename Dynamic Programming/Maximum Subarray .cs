/*Time: O(n)
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
public class Solution {
    public int MaxSubArray(int[] nums) {
        int sum = 0; int maxSum = 0; int nMax = int.MinValue;
        int neg=0;
        for(int i = 0; i<nums.Length; i++){
            sum+=nums[i];
            if(sum > 0) maxSum = Math.Max(maxSum , sum);
            else{
                neg++;
                nMax = Math.Max(nums[i], nMax);
                sum = 0;
            }
               
        }
        if(neg == nums.Length) return nMax;
        return Math.Max(sum , maxSum);
    }
}