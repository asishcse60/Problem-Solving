/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).*/
public class Solution {
    public int MaxProfit(int[] prices) {
       int sum = 0;
       int maxProfit = 0;
       for(int i = 1; i<prices.Length; i++){
       
             if(prices[i] > prices[i-1]){
               sum += prices[i] -  prices[i-1];
             }
            else {
                maxProfit+=sum;
                sum = 0;
            }
       }
       maxProfit+=sum;
       return maxProfit; 
    }
}