class Solution {
public:
    string phone[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void comb(const string digits, string str, int len, vector<string> &ans){
         if(digits.size() == len){ans.push_back(str); return;}
         int dg = digits[len]-'0';
         for(int i = 0; i<phone[dg].size();i++){
             str = str + phone[dg][i];
             comb(digits,str,len+1,ans);
             str = str.substr(0,str.size()-1);
         }
         return;
    }
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string>ans;
        int sz = digits.size();
        comb(digits,"",0,ans);
        return ans;
        
    }
};