class Solution {
public:
    int atoi(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = strlen(s), i, j, k, MAX=2147483647,pos=0,neg=0;
        long long sum = 0, MIN = 2147483648;
        for(i=0;s[i]==' ';i++);
        if(i==sz) return 0;
        if(s[i] == '+') {pos++;i++;}
        else if(s[i] == '-'){neg++;i++;}
        for(;i<sz;i++)
        {
            
            if(s[i]>='0' && s[i]<='9'){
                sum = sum*10 + (s[i]-'0');
                if(pos && sum > MAX) return MAX;
                else if(neg && sum>MIN) return -1*MIN;
            }
            else break;
        }
        if(neg==0 && sum > MAX) return MAX;
        else if(neg && sum>MIN) return -1*MIN;
        else if(neg) sum*=-1;
        return (int)sum;
    }
};