/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int> >ans;
    
    void Call(int cur, int k, int n,vector<int>&l,vector<int>&tmp){
         if(l.size() == k){
             ans.push_back(l);
             return;
         }
         for(int i = cur; i<n; i++){
             l.push_back(tmp[i]);
             Call(i+1,k,n,l,tmp);
             l.pop_back();
         }
        
         return;
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int>l;
        vector<int>tmp;
        l.clear(); tmp.clear(); ans.clear();
        if(n == 0) return ans;
        for(int i = 1; i<=n; i++) tmp.push_back(i);
        Call(0,k,n,l,tmp);
        return ans;
    }
};