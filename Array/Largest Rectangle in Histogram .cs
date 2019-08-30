/*Time:O(N)
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram*/
public class Solution {
    public int LargestRectangleArea(int[] height) {
        int size = height.Length;
        int maxArea = 0;
        int startIndex = 0;
        Stack<int>stack = new Stack<int>();
        
        while(startIndex < size){
        
            if(stack.Count==0 || height[stack.Peek()]<=height[startIndex]){
                stack.Push(startIndex++);
            }
            else{
                int num = height[stack.Pop()];
                int area = num * (stack.Count==0? startIndex:startIndex - stack.Peek() - 1);
                maxArea = Math.Max(maxArea, area);
            }
        
        }
        while(stack.Count>0){
            int num = height[stack.Pop()];
            int area = num * (stack.Count==0? startIndex:startIndex - stack.Peek() - 1);
            maxArea = Math.Max(maxArea, area);
        
        }
        return maxArea;
    }
}