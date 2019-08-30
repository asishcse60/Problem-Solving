using System;
using System.Collections;
public class Entry
{
    Queue Q = new Queue();
    public void Enter(string passportNumber)
    {
        Q.Enqueue(passportNumber);
    }

    public string Leave()
    {
        if (Q == null || Q.Count == 0) return null;
        var q = (string)Q.Dequeue();
        return q;
    }

    public static void Main(string[] args)
    {
        Entry entry = new Entry();
        entry.Enter("AB54321");
        entry.Enter("UK32032");
        Console.WriteLine(entry.Leave());
        Console.WriteLine(entry.Leave());
    }
}