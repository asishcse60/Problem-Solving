/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = S.size(), i, j;
        vector<vector<int> >ans;
        vector<int>tmp;
        map<vector<int>, int>hmap;
        if(sz == 0) return ans;
        tmp.clear(); ans.clear(); hmap.clear();
        sort(S.begin(),S.end());
        for(i = 0; i<(1<<sz); i++)
        {
            for(j = 0; j<sz; j++)
              if(i & (1<<j))
               tmp.push_back(S[j]);
            if(!hmap[tmp]) {hmap[tmp] =  1; ans.push_back(tmp);} 
            tmp.clear();
        }
        
    }
};