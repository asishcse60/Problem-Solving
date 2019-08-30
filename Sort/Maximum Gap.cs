/*Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Timecomplexity : O(n+k)
Try to solve it in linear time/space.*/
public class Solution {
    public int MaximumGap(int[] nums) {
     int maxV = int.MinValue;
     int minV = int.MaxValue;
     int maxGap = int.MinValue;
     if(nums.Length<2) return 0;
     maxV = minV = nums[0];
     for(int i = 1; i<nums.Length; i++){
       if(nums[i] > maxV) maxV = nums[i];
       else if(minV > nums[i]) minV = nums[i];
     }
       int bucketSize = Math.Max(1,(maxV - minV)/(nums.Length - 1)); 
       int bucketNum = (maxV - minV) / (bucketSize + 1);
       if(bucketNum<=1) return maxV - minV;
       int last_max = minV;
       List<int>bucketMin = new List<int>();
       List<int>bucketMax = new List<int>();
       for(int i = 0; i<100000; i++){
           bucketMin.Add(int.MaxValue);
           bucketMax.Add(int.MinValue);
       }
       for(int i = 0;i<nums.Length; i++){
          int bucketId  = (nums[i]- minV)/bucketSize;
          bucketMin[bucketId] = nums[i] < bucketMin[bucketId]? nums[i] :  bucketMin[bucketId];
          bucketMax[bucketId] = nums[i] > bucketMax[bucketId]? nums[i] :  bucketMax[bucketId]; 
       }
       for(int i = 0; i<nums.Length; i++){
         if(bucketMin[i]!=int.MaxValue)
          maxGap = Math.Max(maxGap, bucketMin[i] - last_max);
         if(bucketMax[i]!=int.MinValue) 
         last_max = bucketMax[i];
       }
       return maxGap;
    }
}