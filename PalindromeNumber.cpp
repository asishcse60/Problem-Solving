class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x<0) return 0;
        int mul=1 , left, right;
        while(x/mul>=10) mul*=10;
        while(x!=0){
            left = x/mul;
            right = x%10;
            if(left!=right) return 0;
            x = (x%mul)/10;
            mul/=100;
        }
        return 1;
    }
};