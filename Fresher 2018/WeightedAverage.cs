using System;
using System.Collections.Generic;

public class WeightedAverage
{
    public static double Mean(IList<int> numbers, IList<int> weights)
    { 
        if (numbers==null || weights==null || numbers.Count != weights.Count || weights.Count == 0 )
            {
                throw new ArgumentException();
            }
            double total = 0;
            double totalWeights = 0;
            for (int i = 0; i < numbers.Count; i++)
            {
                total += (numbers[i] * weights[i])*1.0;
                totalWeights += weights[i]*1.0;
            }

            return (double)total / totalWeights;
    }

    public static void Main(string[] args)
    {
        int[] values = new int[] { 3, 6 };
        int[] weights = new int[] { 4, 2 };

        Console.WriteLine(WeightedAverage.Mean(values, weights));
    }
}