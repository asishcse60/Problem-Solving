/*
Write a function to find all unique triple a+b+c=0.
*/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<vector<int> > threeSum(vector<int> &num){
     vector<int>ans_3(3);
     vector<vector<int> >ans;
     vector<int>::iterator i1,i2,i3,last;
     bool f1,f2,f3;
     sort(num.begin(),num.end());

     if(num.size()>=3){
        i1 = num.begin();
        last = num.end();
        f1=false;
        for(;i1!=last-2;i1++){
            if(f1 && *i1==*(i1-1)) continue;f1=true;
            f2=f3=false;
            i2=i1+1;
            i3=last-1;
            while(i2!=i3){
              if(f3 && *i3==*(i3+1)) {i3=i3-1;continue;}
              if(f2 && *i2==*(i2-1)) {i2=i2+1;continue;}

              if(*i1 + *i2 + *i3 == 0){
                 ans_3.at(0) = *i1;
                 ans_3.at(1) = *i2;
                 ans_3.at(2) = *i3;
                 ans.push_back(ans_3);
              }
              if(*i1 + *i2 + *i3 > 0){
                 i3=i3-1;
                 f3=true;
              }else{
                 i2 = i2 + 1;
                 f2 =true;
              }
            }
        }
     }
     return ans;
}
int main(){
    int i, j, k, len;
    threeSum();
    return 0;
}
