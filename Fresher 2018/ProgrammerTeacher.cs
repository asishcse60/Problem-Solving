using System;
using System.Collections.Generic;
using System.Linq;

public class Programmer {

    public Programmer()
    {
        Languages = new List<string>();
    }
    public void AddLanguage(string language)
    {
        Languages.Add(language);
    }
    public List<string> Languages { get; set; }
}

public class ProgrammerTeacher : Programmer {

    public bool Teach(Programmer P, string laguage)
    {
        var lan =Languages.FirstOrDefault(f=>f == laguage);
        if (lan == null) return false;
        P.Languages.Add(laguage);
        return true;
    } 
}

public class Program
{
    public static void Main(string[] args)
    {
        ProgrammerTeacher teacher = new ProgrammerTeacher();
        teacher.AddLanguage("C#");

        Programmer programmer = new Programmer();
        teacher.Teach(programmer, "C#");

        foreach (var language in programmer.Languages)
            Console.WriteLine(language);
    }
}