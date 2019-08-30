/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution {
public:
    string multiply(string ch1, string ch2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1,len2,i,j,k,l,temp,carry,sum;
        char ch3[20000];
        if(ch1[0]=='0'||ch2[0]=='0') return "0";
        len1=ch1.size();
    	len2=ch2.size();
        for(i=0;i<(len1*len2)+2;i++) ch3[i] = 0;
        for(l=0,i=len2-1;i>=0;i--){
    		for(k=l,carry=0,j=len1-1;j>=0;j--){
				temp=(ch1[j]-48)*(ch2[i]-48)+carry;
				if(ch3[k]!=0)
					temp+=ch3[k]-48;
				sum=temp%10;
				carry=temp/10;
				ch3[k] = (sum+48);
					k++;
			}
			if(carry>0)
				ch3[k++]=(carry+48);
            ch3[k] = '\0';        
			l++;
		}
        int sz = strlen(ch3) - 1; string P="";
        for(i = sz;i>=0; i--){
           P+=ch3[i];
        }
        return P;
    }
};