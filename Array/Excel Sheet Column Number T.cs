Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
public class Solution {
    public int TitleToNumber(string s) {
        
        int len = s.Length;
        int sum = s[0] - 64;
        for(int i =1; i<len; i++){
          sum = sum*26 + Convert.ToInt32(s[i] - 64);
        }
        return sum;
    }
}