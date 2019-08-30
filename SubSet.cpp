/*
Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = S.size(), i, j;
        vector<vector<int> >ans;
        vector<int>tmp; tmp.clear(); ans.clear();
        if(sz==0) return ans;
        sort(S.begin(),S.end());
        for(int i = 0; i<(1<<sz);i++)
         {
             for(int j = 0; j<sz; j++)
               if(i & (1<<j))
                 tmp.push_back(S[j]);
             ans.push_back(tmp);
             tmp.clear();
             
         }
        return ans;
    }
};