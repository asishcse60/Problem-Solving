#include<iostream>
#include<cstring>
using namespace std;

int P[1005];
string Process(string str){
  int sz = str.size();
  if(sz == 0) return "^$";
  string form = "^";
  for(int i = 0;i<sz; i++){
        form += "#" + str.substr(i,1);
        P[i] = 0;
  }
  form+="#$";
  return form;
}
int main(){
    int i, j, k, len;
    string str, newStr;
    cin>>str;
    newStr = Process(str);
    //cout<<newStr<<endl;
    len = newStr.size();
    int right = 0, center =0;
    for(i = 1; i<len; i++){
      int mirror_pos = center*2 - i;
      if(right > i) P[i] = min(right-i,P[mirror_pos]);
      else P[i] = 0;
      //cout<<"i: "<<i<<" center: "<<center<<" mirror_pos: "<<mirror_pos<<" Pi "<<P[i]<<endl;
      while(newStr[i+1+P[i]] == newStr[i-1-P[i]]) P[i]++;
      if(i+P[i]>right){
        center = i;
        right = i+P[i];
      }
      //cout<<"i: "<<i<<" center: "<<center<<" right: "<<right<<" Pi "<<P[i]<<endl;
    }

    int cIdx = 0, mLen = 0;
    for(i=1;i<len-1;i++){
        if(P[i]>mLen){
          mLen = P[i];
          cIdx = i;
        }
    }
    if(newStr[cIdx -1 - mLen] == '#') mLen--;
    cout<<mLen<<" "<<str.substr((cIdx - mLen)/2,mLen)<<endl;
    return 0;
}
