using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
public class Product
{
    public string Name { get; }
    private int quantity;
    public int Quantity
    {
        get
        {
            return this.quantity;
        }
        set
        {
            this.quantity = value < 1 ? 1 : value;
        }
    }

    public Product(string name, int quantity)
    {
        this.Name = name;
        Quantity = quantity;
    }
}