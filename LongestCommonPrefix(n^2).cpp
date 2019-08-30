/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
#include<iostream>
#include<cstring>
using namespace std;

string longestCommonPrefix(vector<string> &str) {
   int sz = str.size(), i,j,idx=0;
   if(sz==0) return "";
   for(i=0;i<str[0].size();i++)
    for(j=1;j<sz;j++)
     if(str[j].size()>=i && str[j][i]!=str[0][i]){
        return str[0].substr(0,i);
     }
     return str[0].substr(0,i);
}
int main(){
    int i, j, k, len;
    longestCommonPrefix();
    return 0;
}
