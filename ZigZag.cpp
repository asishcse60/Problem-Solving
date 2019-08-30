//Complextity: O(nRows*s.length)
#include<iostream>
#include<string.h>
using namespace std;
string s,ss,str[1007];
int main(){
    int i , j, k, rr,cnt=0,row=0,col=0;
    cin>>s>>rr;
    k = s.size();
    for(i = 0; i<k; i++)
    for(j =0;j<k;j++) str[i][j]='#';
    cnt=0;
   if(rr<=0 || k == 0) cout<<""<<endl;
   else if(rr==1 || rr>=k) cout<<s<<endl;
   else{
   while(cnt<k)
   {
        if(row<rr){
            str[row][col] = s[cnt++];
            row++;
        }
        else{
            col++;
            for(i = rr - 2; i>0; i--){
                str[i][col] = s[cnt++];
                if(cnt>=k) break;
                col++;
            }row=0;
            if(cnt>=k) break;
        }

   }ss="";
  // cout<<rr<<" "<<col<<endl;
   for(i=0;i<rr;i++)
    for(j=0;j<=col;j++)
     if(str[i][j]!='#')
       ss.push_back(str[i][j]);

    cout<<ss<<endl;
 }

  return 0;
}
