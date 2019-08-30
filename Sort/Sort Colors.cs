//Complexity: O(n)
/*Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.*/
public class Solution {
    public void SortColors(int[] nums) {
        
        int blue = nums.Length - 1;
        int red = 0;
        int temp;
        for(int i = 0; i<=blue; ){
        
           if(nums[i] == 0){
               temp = nums[i];
               nums[i] = nums[red];
               nums[red] = temp;
               red++;i++;
           }
           else if(nums[i]==2){
               temp = nums[i]; // x^=y^=x^=y;
               nums[i] = nums[blue];
               nums[blue ] = temp;
               blue--;
           }
           else
           i++;
        }
    }
}