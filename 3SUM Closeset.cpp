/*
Write a function to find all unique triple a+b+c=target as near.
*/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

    int threeSumClosest(vector<int> &num, int t) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
             int ans_3;
     vector<int>::iterator i1,i2,i3,last;
     bool f1,f2,f3;
     sort(num.begin(),num.end());

     if(num.size()>=3){
        i1 = num.begin();
        last = num.end();
        ans_3=num.at(0) + num.at(1) + num.at(2);
        f1=false;
        for(;i1!=last-2;i1++){
            if(f1 && *i1==*(i1-1)) continue;f1=true;
            f2=f3=false;
            i2=i1+1;
            i3=last-1;
            while(i2!=i3){
              if(f3 && *i3==*(i3+1)) {i3=i3-1;continue;}
              if(f2 && *i2==*(i2-1)) {i2=i2+1;continue;}

              if(*i1 + *i2 + *i3 == t){
                  ans_3 = t;
                  return ans_3;
              }
              if(*i1 + *i2 + *i3 > t){
                 if(abs(t-(*i1+*i2+*i3))<abs(t-ans_3))
                    ans_3=*i1+*i2+*i3;
                 i3=i3-1;
                 f3=true;
              }else{
                  if(abs(t-(*i1+*i2+*i3))<abs(t-ans_3))
                    ans_3=*i1+*i2+*i3;
                 i2 = i2 + 1;
                 f2 =true;
              }
            }
        }
     }
     return ans_3;

    }
int main(){
    int i, j, k, len;
    threeSum();
    return 0;
}
