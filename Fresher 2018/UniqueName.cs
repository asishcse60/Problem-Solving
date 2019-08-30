using System;
using System.Collections;
using System.Collections.Generic;
public class UniqueName
{
    public static string FirstUniqueName(string[] names)
    {
        Dictionary<string, int> Dic = new Dictionary<string, int>();
        string firstName = null;
        foreach(var name in names)
        {
            if(Dic.ContainsKey(name) == false)
            {
                Dic.Add(name, 1);
            }
            else
            {
                Dic[name] = 2;
            }
        }
        foreach(var ds in Dic)
        {
            if(ds.Value == 1)
            {
                return ds.Key;
            }
        }
        return firstName;
    }

    public static void Main(string[] args)
    {
        Console.WriteLine(FirstUniqueName(new string[] { "Abbi", "Adeline", "Abbi", "Adalia" }));
    }
}