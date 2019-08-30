/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1 = a.size(), l2 = b.size(),i,j,k=0; string s="",ss="";
        if(l1==0) return b; if(l2==0) return a;
        for(i = l1-1,j = l2-1;i>=0 || j>=0; i--,j--){
            if(i>=0 && j>=0){
                if(a[i]=='1' && b[j]=='1'){
                    if(k)
                      s.push_back('1');
                      else s.push_back('0');  
                    k=1;
                }
                else if(a[i]=='0' && b[j] == '0'){
                    
                     if(k) s.push_back('1');
                     else s.push_back('0');k=0;
                }
                else if(a[i]=='0' && b[j]=='1'){
                    
                    if(k){
                      s.push_back('0');k=1;}
                      else {s.push_back('1');k=0;}    
                }
                  else if(a[i]=='1' && b[j]=='0'){
                    
                    if(k){
                      s.push_back('0');k=1;}
                      else {s.push_back('1');k=0;}    
                }
            }
            else if(i>=0){
                if(a[i] == '1') {if(k) {s.push_back('0'); k=1;} else {s.push_back('1');k=0;}}
                else if(a[i]=='0') {if(k) {s.push_back('1'); k=0;} else {s.push_back('0');k=0;}}
            }
            else if(j>=0){
                if(b[j] == '1') {if(k) {s.push_back('0'); k=1;} else {s.push_back('1');k=0;}}
                else if(b[j]=='0') {if(k) {s.push_back('1'); k=0;} else {s.push_back('0');k=0;}}
            }
        }
        if(k) s.push_back('1');
        for(i = s.size()-1;i>=0;i--) ss.push_back(s[i]);
        return ss;
    }
};