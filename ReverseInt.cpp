class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int neg = 1, rem = 0;
        if(x<0) {neg = -1; x*=-1;}
        while(x){
            rem = rem*10 + x%10;
            x/=10;
        }
        return rem*neg;
    }
};