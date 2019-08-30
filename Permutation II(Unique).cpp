/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

class Solution {
public:
    bool isSame(int fst, int lst, vector<int>num){
        for(int  j = fst; j<lst; j++)
          if(num[j] == num[lst]) return 1;
        return 0;  
    }
    void Perm(int start, int end, vector<vector<int> > &ans, vector<int>num){
        if(start==(end-1)){
            ans.push_back(num);
            return;
        }
        else{
            
              for(int i = start; i<end; i++){
                  if(isSame(start, i, num)) continue;
                  swap(num[start], num[i]);
                  Perm(start+1,end,ans, num);
                  swap(num[start], num[i]);
              }
        }
        
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >ans;
        if(num.size()==0) return ans;
        Perm(0, num.size(), ans, num);
        return ans;
    
    }
};