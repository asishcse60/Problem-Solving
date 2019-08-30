using System;
using System.Collections.Generic;
using System.Linq;

public class Node
{
    public Node LeftChild { get; private set; }
    public Node RightChild { get; private set; }

    public Node(Node leftChild, Node rightChild)
    {
        this.LeftChild = leftChild;
        this.RightChild = rightChild;
    }

    public int Height()
    {
        if (this == null) return 0;

        int lDepth = 0;
        int rDepth = 0;
        if (LeftChild != null)
            lDepth = LeftChild.Height() + 1;
        if(RightChild != null)
        {
           rDepth = RightChild.Height() + 1;
        }
     
       return Math.Max(lDepth, rDepth);
    }

    public static void Main(string[] args)
    {
        Node leaf1 = new Node(null, null);
        Node leaf2 = new Node(null, null);
        Node node = new Node(leaf1, null);
        Node root = new Node(node, leaf2);

        Console.WriteLine(root.Height());
    }
}