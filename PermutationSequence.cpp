/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/
class Solution {
public:

    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        string  result;
        vector<int> num(n);
        int i, d(1), q;
        for(i=1;i<=n;++i){
            num[i-1]  = i;
            d        *= i;  //d=n!
        }
        for(i=n;i>=1;--i){
            d       = d/i;
            q       = (k-1)/d;
            k       = k-q*d;
            result.push_back('0'+num[q]);
            num.erase(num.begin()+q);
        }
        return result;
        
    }
};