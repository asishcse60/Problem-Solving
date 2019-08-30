/*O(n)  and nlogn First we have the sort this array, then first element > 1 return 1 otherwise dfference b - a>1 return b+1*/
public class Solution {
    public int FirstMissingPositive(int[] nums) {
        ISet<int>hashSet = new HashSet<int>();
        
        for(int i = 0; i<nums.Length; i++)
         if((nums[i] > 0) &&!hashSet.Contains(nums[i]))
             hashSet.Add(nums[i]);
         for(int i = 1; i<=nums.Length; i++){
               if(!hashSet.Contains(i)) return i;
           }
         return  nums.Length + 1;
    }
}