using System;

public class PaperStrip
{
    public static int MinPieces(int[] original, int[] desired)
    {
        int n = original.Length;

        int[] positionInDesired = new int[n + 1];
        for (int i = 0; i < n; i++)
            positionInDesired[desired[i]] = i;

        int blocks = 1;
        for (int i = 0; i < n - 1; i++)
            if (positionInDesired[original[i]] + 1 != positionInDesired[original[i + 1]])
                ++blocks;

        return blocks;
    }
}