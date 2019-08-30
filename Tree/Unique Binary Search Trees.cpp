/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
class Solution {
public:
    int numTrees(int n) {
        //Catalan number (2n)! / (n+1)!n!
        long long numOfBst = 1;
        for(int i = 2; i<=n; i++){
            numOfBst = numOfBst * 2 * (2 * i - 1) / (i + 1);
        }
        return numOfBst;
    }
};

public class Solution {
    public int NumTrees(int n) {
        long  numOfUniqueBst = 1;
        for(int startBstCount = 2; startBstCount<=n; startBstCount++){
            numOfUniqueBst = numOfUniqueBst * 2 * (2 * startBstCount - 1) / (startBstCount + 1);
        }
        return (int)numOfUniqueBst;
    }
}
