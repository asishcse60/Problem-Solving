using System;
using System.Collections.Generic;
using System.Linq;

public class Rare
{
    public static int NthMostRare(int[] elements, int n)
    {
        Dictionary<int, int> Dic = new Dictionary<int, int>();
        foreach(var e in elements)
        {
            if(Dic.ContainsKey(e) == false)
            {
                Dic.Add(e, 1);
            }
            else
            {
                Dic[e] += 1;
            }
        }
        var dd = Dic.OrderBy(d => d.Value);
        int k = 0;
        foreach(var d in dd)
        {
            k++;
            if (k == n) return d.Key;
        }
        return k;
    }

    public static void Main(string[] args)
    {
        int x = NthMostRare(new int[] { 5, 4, 3, 2, 1, 5, 4, 3, 2, 5, 4, 3, 5, 4, 5 }, 2);
        Console.WriteLine(x);
    }
}