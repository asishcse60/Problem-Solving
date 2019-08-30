using System;
using System.Collections.Generic;

public class Train<T>
{
    private readonly T[] wagons;

    public Train(int wagonCount, Func<int, T> fillWagon)
    {
        this.wagons = new T[wagonCount];

        for (int i = 0; i < wagonCount; i++)
        {
            this.wagons[i] = fillWagon(i);
        }
    }

    public T PeekWagon(int wagonIndex)
    {
        return (T)this.wagons[wagonIndex];
    }
}

public class TrainStation
{
    public static void Main(string[] args)
    {
        Train<string> train = new Train<string>(10, wagonIndex => "Wagon: " + wagonIndex);

        for (int i = 0; i < 10; i++)
        {
            Console.WriteLine(train.PeekWagon(i));
        }
    }
}