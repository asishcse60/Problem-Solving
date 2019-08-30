class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int,int>mp;
        if(n==0) return 1;
        for(int i = 0;i<n;i++)
         if(A[i]>0) mp[A[i]] = 1;
         for(int i = 1; i<=n; i++)
          if(mp[n-(n-i)] == 0) return n-(n-i);
        return n+1;
    }
};
/* without additional space
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        for (int i = 0; i<n;i++){
            if ( (A[i]>0)&&(A[i]<=n)){
                while (A[i]!=(i+1)){
                    if ((A[i]>n)||(A[i]<=0)||(A[A[i]-1]==A[i])) {break;}
                    int tmp;
                    tmp = A[A[i]-1];
                    A[A[i]-1]=A[i];
                    A[i]=tmp;
                }
            }
        }
         
        int i=0;
        for (; i<n;i++){
            if (A[i]!=(i+1)){
                return i+1;
            }
        }
        return i+1;
         
    }
};
*/