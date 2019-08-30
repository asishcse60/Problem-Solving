/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

class Solution {
public:
 void perm(vector<int> num,int k,int n, vector<vector<int> > &res){
        if (k==(n-1)){
            res.push_back(num);
        }else{
            for (int i=k;i<n;i++){
                swap(num[k],num[i]);
                perm(num,k+1,n,res);
                swap(num[k],num[i]);
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        perm(num,0,num.size(),res);
        return res;
        
    }
};