/*Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.*/
class Solution {
  
public:
    int compareString(string x, string y){
     string xy = x.append(y);
     string yx = y.append(x);
     return xy.compare(yx) > 0? 1:0;
    }
    string largestNumber(vector<int>& nums) {
        if(nums.size()== 0) return "";
        sort(nums.begin(), nums.end(), compareString);
        string largestString = "";
        for(int i = 0; i<nums.size(); i++)
          largestString = largestString.append(nums[i]);
         return largestString;
    }
};