//Complextity: O(nRows*s.length)
#include<iostream>
#include<string.h>
using namespace std;
string intToRoman(int n){
  int Num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  string R[] ={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"},S="";

    for(int i=0; i<13;i++)
      while(n>=Num[i]){
          S+=R[i];
          n-=Num[i];
      }

  return S;
}
int main(){
    int n;
    while(cin>>n){
    cout<<intToRoman(n)<<endl;
    }
  return 0;
}
