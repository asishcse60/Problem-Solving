/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ? 1,3,2
3,2,1 ? 1,2,3
1,1,5 ? 1,5,1
*/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = num.size(), i, j,k;
        for(i = sz - 2; i>=0;i--)
            if(num[i]<num[i+1]){
                for(j = i+1;j<sz;j++)
                  if(j == sz-1 || num[i]>=num[j+1]){
                      swap(num[i],num[j]);
                      reverse(num.begin()+i+1, num.end());
                      return;
                  }
            }
        reverse(num.begin(), num.end());
    }
};