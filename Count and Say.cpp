/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
using namespace std;
string countAndSay(int n){
  string s="1";
  if(n==1) return s; s="11";
  if(n==2) return s;n-=2;
  while(n){
     int cnt = 1;string ss="",tmp="";
     for(int i = 0; i<s.size(); i++){
          if(s[i] == s[i+1]) cnt++;
          else{
               ostringstream convert;
               convert<<cnt;
               tmp = convert.str();
               ss+=tmp+s[i];
               cnt=1;
          }
     }s=ss;n--;
  }return s;

}

int main(){
  int i, j, k,n;
  while(cin>>n){
    cout<<countAndSay(n)<<endl;
  }
  return 0;
}
