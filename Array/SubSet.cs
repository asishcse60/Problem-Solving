/*O(2^N)
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:
*/

public class Solution {
    public List<List<int>> Subsets(int[] nums) {
    
        List<int>list = new List<int>();
        List<List<int>>ans = new List<List<int>>();
        int size = nums.Length;
        Array.Sort(nums);
        for(int i = 0; i<(1<<size); i++){
            for(int j = 0; j<size; j++){
              if((i & (1<<j)) > 0){
                list.Add(nums[j]);
              }
            }
            ans.Add(list);
            list = new List<int>();
        }
        return ans;
    }
}