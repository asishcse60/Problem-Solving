using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Star
{
    public double ShineFactor { get; set; }
    public string Name { get; set; }
    public bool IsFadeOut { get; set; }
    public Star(double shineFactor)
    {
        ShineFactor = shineFactor;
    }
    public double Shine()
    {
        if (IsFadeOut)
        {
            throw new InvalidOperationException();
        }
        IsFadeOut = false;
        return ShineFactor;
    }
    public void FadeOut()
    {
        IsFadeOut = true;
    }
    //Write the code here
}