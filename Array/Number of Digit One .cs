Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
O(log n)

public class Solution {
    public int CountDigitOne(int n) {
        long bas = 1;
        long res = 0;
        long last = 0;
        int k = 1; // because we have count digit 1
        while(n >= bas){
            int ind = (n/(int)bas)%10;
            long remain = n - (n/(int)bas) * bas;
            if(ind == k){
                res = res + (ind*last) + remain + 1;
            }
            else if(ind > k){
                res = res + (ind * last) + bas;
            }
           else{
               res = res +(ind * last);
           }
           last = last*10 + bas;
           bas = bas * 10;
        }
        return (int)res;
    }
}