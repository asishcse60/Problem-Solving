#include<iostream>
#include<map>
using namespace std;

int main(){

    int i, j, k = 7, num[1005], ans = 0;
    map<int,int>mp;mp.clear();
    for(i = 0;i<k; i++){
       cin>>num[i];
       mp[num[i]] = 1;
    }

    for(i=0;i<k;i++){
       int mx  = 1;
       int d = num[i];
       mp.erase(d);
       while(mp.find(d+1)!=mp.end()){
          mx++;
          mp.erase(d+1);
          d++;
       }
        d = num[i];
        while(mp.find(d-1)!=mp.end()){
          mx++;
          mp.erase(d-1);
          d--;
       }
       if(mx>ans) ans = mx;
    }
    cout<<ans<<endl;
}
