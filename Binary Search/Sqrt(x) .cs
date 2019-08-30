/*Implement int sqrt(int x).*/
public class Solution {
    public int MySqrt(int x) {
        
        if(x<=1) return x;
        long low = 0; long up = x; 
        long mid =1;
        while(low<=up){
            mid = (low + up)/2;
            long val = mid * mid;
            if(val > x) up = mid-1;
            else if(val == x) return (int)mid;
            else low = mid + 1;
           
        }
        if(low*low<=x) return (int)low;
        return (int)low-1;
    }
}