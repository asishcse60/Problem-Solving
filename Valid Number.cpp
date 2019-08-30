/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/
class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int d=0, dot=0, e=0,l=0, len = strlen(s),ii,jj,j,p=0,sp=0;
        const char *ss=s;
       // strcpy(ss,s);
        char ch;
        for(ii = 0;;ii++) if(s[ii]!=' ') break; else sp++;
        for(jj = len-1; ; jj--) if(s[jj]!=' ') break;else sp++;
        
       if(s[ii]=='+' || s[ii]=='-'){ii++;}
       //if(s[jj]=='+' || s[jj]=='-') { jj--;}
        j=ii;
        while(ii<=jj){
            if(isdigit(s[ii])) {ii++;d++;}
            else if(s[ii]=='.') {ii++;dot++;}
            else if(isalpha(s[ii])) {l++;ch=s[ii];ii++;}
            else if(s[ii]=='+' || s[ii]=='-') {p++;ii++;}
            else {ii++;e++;}
        }
        if(e>0) return 0;
        if(p>1) return 0;
        if(p==1 && ch!='e') return 0;
        if(dot>1) return 0;
        if(l>1) return 0;
        else if(d>0 && (dot==0) && (l==0)) return 1;
        else if(d>0 && (dot==1) && (l==0)) return 1;
        else if(d>0 && (dot==0) && (l==1)){
            if(ch=='e'){ 
                int i,d=0;
                if(s[j]=='e' && isdigit(s[j+1])) return 0;
                while(j<=jj){
                  if(isdigit(s[j])) {j++; d=1;}
                  else if(s[j]=='e' && (j+1)<=jj && isdigit(s[j+1]))
                      j+=2;
                  else if(d && s[j]=='e' && (j+2)<=jj && ( s[j+1]=='+'||s[j+1]=='-') && isdigit(s[j+2]))
                   j+=3;
                  else 
                     return 0;
                }
              return 1;          
            }
        }
            else if(d>0 && (dot==1) && (l==1))
            {//return 1;
             if(s[j]=='.' && s[j+1]=='e') return 0;
                int c=0,d=0;
                if(ch=='e'){ 
                    while(j<=jj)
                    {
                     if(isdigit(s[j])) {j++;d=1;}
                     else if(s[j]== '.' && j+1<=jj) {if(c) return 0; j++;}      
                     else if(s[j]=='e' && (j+1)<=jj && isdigit(s[j+1])){
                         j+=2;
                         c=1;
                     }
                     else if(d && s[j]=='e' && (j+2)<=jj && ( s[j+1]=='+'||s[j+1]=='-') && isdigit(s[j+2]))
                            {j+=3;c=1;}
                     else 
                        return 0;
                     }   
                     return 1;  
            }
            
            else return 0;
        }
        return 0;
    }
};