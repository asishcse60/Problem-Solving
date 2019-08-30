Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
public class Solution {
    public string ConvertToTitle(int n) {
        
        string title = string.Empty;
        if(n == 0) return title;
        while(n > 0){
        
            title+=Convert.ToChar('A' + (n-1)%26);
            n = (n-1)/26;
        }
        char [] ch = title.ToCharArray();
        Array.Reverse(ch);
        title = new string(ch);
        return title;
    }
}