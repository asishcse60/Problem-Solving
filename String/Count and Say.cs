The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
public class Solution {
    public string CountAndSay(int n) {
        string x = "1";
        int [] digit= new int[100];
        for(int j = 1; j<n; j++)
        {
            string s = string.Empty;
            for(int i = 0; i<x.Length; i++){
            digit[x[i]]++;
            if((i+1)<x.Length && x[i]!=x[i+1]){
                s+= Convert.ToString(digit[x[i]])+Convert.ToString(x[i]);
                digit[x[i]] = 0;
            }
            
        }
        for(char a = '1'; a<='9'; a++)
          if(digit[a] > 0){
               s+= Convert.ToString(digit[a])+Convert.ToString(a);
               digit[a] = 0;
           }
           x = s;
      }
        return x;
    }
}