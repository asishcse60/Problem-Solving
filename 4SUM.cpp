/*
Write a function to find all unique quartple a+b+c+d=t.
*/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int t){
     vector<int>ans_3(4);
     vector<vector<int> >ans;
     vector<int>::iterator i1,i2,i3,last;
     bool f1,f2,f3,f4;
     sort(num.begin(),num.end());
     int n = num.size(), left,right,i,j;
     if(n>=4)
     {
         for(i=0;i<n;i++){
            if(i!=0 && num[i] == num[i-1]) continue;
            for(j = n-1;j>i; j--){
               if(j!=n-1 && num[j] == num[j+1]) continue;
               left = i+1; right=j-1;
               while(left<right){
                   int sum = num[i] + num[j] + num[left] + num[right];
                 if(left!= i+1 && num[left] == num[left-1]) left++;
                 else if(right != j-1 && num[right] == num[right+1]) right--;
                 else if(sum>t) right--;
                 else if(sum<t) left++;
                 else{
                        ans_3.at(0) =  num[i];
                        ans_3.at(1) =  num[left];
                        ans_3.at(2) =  num[right];
                        ans_3.at(3) =  num[j];
                        ans.push_back(ans_3)
                     left++;right--;
                 }

               }
            }
         }
     }
     return ans;
}
int main(){
    int i, j, k, len;
    fourSum();
    return 0;
}
