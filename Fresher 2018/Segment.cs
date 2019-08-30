using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Segment
{
    public static Tuple<double, double> Areas(double r, double a)
    {
        double PI = Math.PI;
        var area = PI * r * r;
        var s = (r * r) / 2.0;
        var ss = (a * PI) / 180.0;
        var sss = Math.Sin(ss);
        var segArea = s*(ss-sss);
        var tuple = new Tuple<double, double>(segArea, area - segArea);
        return tuple;
       // throw new NotImplementedException("Waiting to be implemented.");
    }

    public static void Main(string[] args)
    {
        Tuple<double, double> areas = Segment.Areas(10, 90);
        Console.WriteLine("Areas: " + areas.Item1 + ", " + areas.Item2);
    }
}