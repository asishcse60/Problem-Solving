/*There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?*/
public class Solution {

 public  int Candy(int[] ratings)
    {
        if (ratings.Length == 1) return 1;
        int maxCandy = 1;
        var dp = new int[ratings.Length];
        dp[0] = 1;
        for (int i = 1; i < ratings.Length; i++)
        {
           if(ratings[i] > ratings[i - 1]){
               dp[i] = dp[i - 1] + 1;
           }
           else
           dp[i] = 1;
        }
        maxCandy = dp[ratings.Length - 1];
        for (int i = ratings.Length - 2; i>=0; i--)
        {
           if(ratings[i] > ratings[i + 1] && dp[i]<dp[i+1]+1){
               dp[i] = dp[i + 1] + 1;
               
           }
           maxCandy+=dp[i];
        }
        return maxCandy;
    }
}