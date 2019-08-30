/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ? , ak) must be in non-descending order. (ie, a1 ? a2 ? ? ? ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/
class Solution {
public:
 vector<vector<int> >ans;
    void Call(vector<int>&candidates, int start, vector<int>&l, int target){
        
        if(target == 0){
            ans.push_back(l);
            return;
        }
        if(target<0 || start>=candidates.size()) return;
        if(target>=candidates[start]){
            
            int prev = -1;
            for(int idx = start; idx<candidates.size(); idx++){
                
                if(candidates[idx]!=prev){
                      l.push_back(candidates[idx]);
                      Call(candidates, idx, l, target-candidates[idx]);
                      prev = l.back();
                      l.pop_back();
                }
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
        ans.clear();
        if(candidates.size() == 0) return ans;
        sort(candidates.begin(),candidates.end());
        vector<int>l;
        Call(candidates, 0, l, target);
        return ans;
        
    }
};