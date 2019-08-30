using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Branches
{
    public static int Count(params int[] tree)
    {
        return tree.Distinct().Count() - 1;
    }

    public static void Main(string[] args)
    {
        Console.WriteLine(Branches.Count(1, 3, 1, -1, 3));
    }
}