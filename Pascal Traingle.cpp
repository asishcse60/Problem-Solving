/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int> > generate(int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >ans;
        ans.clear(); int prev, cur;
        vector<int>tmp; tmp.clear();
        if(k == 0) return ans;
        tmp.push_back(1); ans.push_back(tmp);
        for(int i = 1; i<k; i++){
              prev = tmp[0];
             for(int j = 1; j<i; j++){
               cur = tmp[j];
               tmp[j] = prev + cur;
               prev = cur;
             } 
             tmp.push_back(1);
             ans.push_back(tmp);
        }
       return ans;        
    }
};