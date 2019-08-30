using System;
using System.Collections.Generic;
using System.Linq;

public class MirrorClock
{
    public static string GetTime(string time)
    {
        var list = time.Split(':');
        var a = Convert.ToInt32(list[0]);
        var b = Convert.ToInt32(list[1]);
        a = 11 - a;
        if (b == 0) a++;

        if (a <= 0)
            a = a + 12;
        if (a != 0)
            b = 60 - b;
        if (b == 60)
            b = 0;
        var aa = Convert.ToString(a);
        var bb = Convert.ToString(b);
        if (aa.Length == 1) aa = "0" + aa;
        if (bb.Length == 1) bb = "0" + bb;
        return string.Format("{0}:{1}",aa,bb);
    }

    public static void Main(string[] args)
    {
        Console.WriteLine(GetTime("01:00"));
    }
}