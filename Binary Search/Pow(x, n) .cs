/*Implement pow(x, n).*/
public class Solution {
    public double MyPow(double x, int n) {
        double result = 1;
        int chk = 0;
        if(n < 0) {chk =1; n*=-1;}
        while(n > 0){
            if(n%2 == 1) result*=x;
            x*=x;
            n/=2;
        }
        if(chk == 1) result = 1.0/result;
        return result;
    }
}