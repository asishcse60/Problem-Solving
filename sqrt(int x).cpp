class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        if(x<=0) return 0;
        if(x==1) return 1;
        int low = 0, high = x; long long mid = low + (high-low)/2;
        while((high-low)>1){
             if((mid*mid)>x) high = mid;
             else low = mid;
             mid = low + (high-low)/2;
        }
        return mid;
    }
};