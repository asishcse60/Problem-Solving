#include<iostream>
using namespace std;

int main(){
    long long tmp,tmp2,c=1,ans=0,sign=1,divide,dividor;
    cin>>divide>>dividor;
    if(divide<0) sign=-sign;
    if(dividor<0) sign=-sign;
    tmp = divide; tmp2 = dividor;
    while(tmp>tmp2){
        tmp2 = tmp2<<1;
        c=c<<1;
        //cout<<c<<" "<<tmp2<<endl;
    }
    while(tmp>=dividor)
    {
         while(tmp>=tmp2){tmp-=tmp2;ans+=c;}
        tmp2>>=1;
        c>>=1;
     // cout<<c<<" "<<tmp2<<" "<<ans<<endl;
    }cout<<ans*sign<<endl;;
    return 0;
}
