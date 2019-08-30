/*Time: O(n)
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
public class Solution {
    public int LongestConsecutive(int[] nums) {
        int size = nums.Length;
        ISet<int>hs = new HashSet<int>();
        for(int i = 0; i<size; i++)
            if(!hs.Contains(nums[i]))
                hs.Add(nums[i]);
        
        int mxLen = 0;
        for(int i = 0;i<size;i++){
          int len = 1;
          int num = nums[i] - 1;
          while(hs.Contains(num)){
             hs.Remove(num);
             len++;num--;
          }
          num = nums[i] + 1;
          while(hs.Contains(num)){
             hs.Remove(num);
             len++;num++;
          }
          mxLen = Math.Max(mxLen , len);
        }
         
       return mxLen;
    }
}