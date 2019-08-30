Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
/**
 Time Complexity: O(n)
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode SortedArrayToBST(int[] nums) {
        return BuildBalanceBst(0, nums.Length - 1, nums);
    }
    
    public TreeNode BuildBalanceBst(int low, int high, int[] nums){
        if(low > high) return null;
        int mid = (low + high)/2;
        TreeNode temp = new TreeNode(nums[mid]);
        temp.left = BuildBalanceBst(low, mid - 1, nums);
        temp.right= BuildBalanceBst(mid + 1, high, nums);
        return temp;
    }
}