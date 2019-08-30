Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
public class Solution {
    public int ComputeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        var I = Math.Min(C,G) > Math.Max(A,E)? Math.Min(C,G) - Math.Max(A,E): 0; 
        var J = Math.Min(D,H) > Math.Max(B,F)? Math.Min(D,H) - Math.Max(B,F): 0; 
        return -(I)*(J)+(D-B) * (C-A) + (H - F)*(G-E);
        
    }
}