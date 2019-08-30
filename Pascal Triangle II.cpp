/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution {
public:
    vector<int> getRow(int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int>tmp;
        int prev , cur;
        tmp.push_back(1);
        for(int i = 1;i<=k; i++){
             prev = tmp[0];
            for(int j = 1;j<i; j++){
                cur= tmp[j];
                tmp[j] = cur + prev;
                prev = cur;                
            }
            tmp.push_back(1);
        }
        return tmp;
    }
};