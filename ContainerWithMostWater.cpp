/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = height.size(), left=0,right=sz-1,mx=0;
        if(sz<2) return 0;
        while(left<right){
            int tt = abs(left-right)*min(height[left],height[right]);
            if(tt>mx) mx=tt;
            if(height[left]<=height[right]) left++;
            else right--;
        }
        return mx;
    }
};