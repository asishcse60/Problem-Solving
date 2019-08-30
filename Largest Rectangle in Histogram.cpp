//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
class Solution {
public:
    int largestRectangleArea(vector<int> &h) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int>T;
        int i =0,sz=h.size(),ans=0;
        h.push_back(0);
        while(i<sz+1){
            if(T.empty() || h[T.top()]<=h[i]) T.push(i++);
            else{
                int top= T.top();
                T.pop();
                ans = max(ans,h[top]*(T.empty()?i:i-T.top()-1));
            }
        }
        return ans;
    }
};