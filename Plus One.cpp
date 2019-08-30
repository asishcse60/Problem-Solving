/*
Given a number represented as an array of digits, plus one to the number
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &d) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = d.size();
        if(d[sz-1]!=9){d[sz-1]++; return d;}
        else{
            d[sz-1] = 0; int c = 1;
            for(int i = sz-2;i>=0;i--){
             if(d[i]!=9 && c){d[i]++;return d;}
             else if(d[i]!=9 && c==0){return d;}
             else{
                 d[i] = 0;c=1;
             }
            }
        }
        vector<int>ans(sz+1,0);
        ans[0] = 1;
        return ans;
        
    }
};