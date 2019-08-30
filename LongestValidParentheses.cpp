#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

int longestValidParentheses(string s){
    int sz = s.size(), i, top, k[20005], pos[20005];
    memset(k,0,sizeof k);
    top=0;
    for(i = 0; i<sz; i++){
       if(s[i] == '('){pos[++top] = i; k[i] = 1;}
       else{
          if(top){
              k[i] = 1;
              --top;
          }
       }
    }

    for(i = 1;i<=top; i++) k[pos[i]] = -1;

    int mx=0,sum=0;

    for(i =0;i<sz;i++)
      {
          if(k[i] == -1 || k[i] == 0) {mx = max(mx,sum); sum=0;}
          else sum+=k[i];
      }
      mx = max(mx,sum);
      //for(i=0;i<sz;i++) cout<<k[i]<<" "; cout<<endl;
      return mx;
}
int main(){

   string s;
   while(cin>>s){
      cout<<longestValidParentheses(s)<<endl;
   }
   return 0;
}
