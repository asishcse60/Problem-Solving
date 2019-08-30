using System;

public class Candies
{
    public static int CountCandies(int startingAmount, int newEvery)
    {
        var cnt = 0;
        while (startingAmount > 0)
        {
            var amount = startingAmount / newEvery;
            var rest = startingAmount % newEvery;
            var eaten = amount * newEvery;
            if(amount>0){
                cnt += eaten;
                 startingAmount = amount + rest;
            }
            else{
                cnt += rest;    
                 startingAmount = 0;
            }
                       
        }
        return cnt;
        
    }

    public static void Main(string[] args)
    {
        Console.WriteLine(Candies.CountCandies(3, 2));
    }
}