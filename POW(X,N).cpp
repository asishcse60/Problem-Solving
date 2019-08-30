class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int neg=0;
        double sum = 1;
        if(n<0) {neg = 1; n*=-1;}
        while(n>0){
            if(n & 1) sum = sum*x;
            x= (x*x);
            n/=2;
        }
        if(neg) return 1.0/sum; 
        return sum;
    }
};