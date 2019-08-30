#include<iostream>
#include<cstring>
using namespace std;

char S[1005];
bool isValid(string s){
    int i, sz = s.size(), fst = 0;
    for(i = 0; i<sz; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            S[++fst] = s[i];
        else{
            if(s[i] == ')'){
                if(S[fst]!='(') return false;
                fst--;
            }
            else if(s[i] == ']'){
                if(S[fst]!='[') return false;
                fst--;
            }
            else if(s[i] == '}'){
                if(S[fst]!='{') return false;
                fst--;
            }
        }
    }
    if(fst==0)
       return true;
    return false;
}

int main(){
    string s;
   while(cin>>s){
    cout<<isValid(s)<<endl;
   }
   return 0;
}
