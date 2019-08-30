using System;
using System.Collections.Generic;
using System.Linq;

public interface IBird
{
    Egg Lay();
}

public class Chicken : IBird
{
    public Chicken()
    {
    }

    public Egg Lay()
    {
        return new Egg(()=>new Chicken());
    }
}

public class Egg
{
    private readonly Func<IBird> _createBird;
    bool isHatched;
    public Egg(Func<IBird> createBird)
    {
        _createBird = createBird;
        isHatched = false;
    }

    public IBird Hatch()
    {
        if (isHatched) throw new InvalidOperationException();
        isHatched = true;
        return _createBird();
    }
}

public class Program
{
    public static void Main(string[] args)
    {
              var chicken1 = new Chicken();
              var egg = chicken1.Lay();
              var childChicken = egg.Hatch();
              var childChicken2 = egg.Hatch();
    }
}