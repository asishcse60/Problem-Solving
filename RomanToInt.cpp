//Complextity: O(nRows*s.length)
#include<iostream>
#include<string.h>
using namespace std;
int romanToInt(string n){
  int Num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1},i,j,sum=0;
  string R[] ={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"},S="";
  for(i = 0;i<n.size();){
    S = n.substr(i,2);
    for(j = 0;j<13; j++){
       if(S==R[j]){sum+=Num[j];i+=2;break;}
    }
    if(j==13){
      S=n.substr(i,1);
       for(int j = 0;j<13; j++){
       if(S==R[j]){sum+=Num[j];i+=1;break;}
    }
    }
  }

  return sum;
}
int main(){
    string n;
    while(cin>>n){
    cout<<romanToInt(n)<<endl;
    }
  return 0;
}
